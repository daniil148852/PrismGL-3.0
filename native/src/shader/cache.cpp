#include "utils/logger.h"

#include <fstream>
#include <iterator>
#include <string>
#include <vector>

namespace prismgl {

static std::string cacheRoot = "/sdcard/PrismGL/cache/shaders";

void setShaderCacheRoot(const std::string &path) {
    cacheRoot = path;
}

std::string getShaderCachePath(const std::string &hash) {
    return cacheRoot + "/" + hash + ".bin";
}

bool loadShaderBinary(const std::string &hash, std::vector<std::uint8_t> &outData) {
    const auto path = getShaderCachePath(hash);
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        return false;
    }
    outData.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
    logInfo("PrismGL", "Shader cache hit.");
    return true;
}

bool storeShaderBinary(const std::string &hash, const std::vector<std::uint8_t> &data) {
    const auto path = getShaderCachePath(hash);
    std::ofstream file(path, std::ios::binary | std::ios::trunc);
    if (!file.is_open()) {
        logWarn("PrismGL", "Failed to write shader cache.");
        return false;
    }
    file.write(reinterpret_cast<const char *>(data.data()), static_cast<std::streamsize>(data.size()));
    logInfo("PrismGL", "Shader cache updated.");
    return true;
}

} // namespace prismgl
