#include "prismgl.h"
#include "utils/logger.h"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

namespace prismgl {

static Config gConfig{};

static float parseFloat(const std::string &content, const std::string &key, float fallback) {
    const auto pos = content.find(key);
    if (pos == std::string::npos) {
        return fallback;
    }
    const auto colon = content.find(':', pos);
    if (colon == std::string::npos) {
        return fallback;
    }
    const auto start = content.find_first_of("0123456789.", colon);
    if (start == std::string::npos) {
        return fallback;
    }
    const auto end = content.find_first_not_of("0123456789.", start);
    return std::stof(content.substr(start, end - start));
}

static std::uint64_t parseBytes(const std::string &content, const std::string &key, std::uint64_t fallback) {
    const auto pos = content.find(key);
    if (pos == std::string::npos) {
        return fallback;
    }
    const auto colon = content.find(':', pos);
    if (colon == std::string::npos) {
        return fallback;
    }
    const auto start = content.find_first_of("0123456789", colon);
    if (start == std::string::npos) {
        return fallback;
    }
    const auto end = content.find_first_not_of("0123456789", start);
    return static_cast<std::uint64_t>(std::stoull(content.substr(start, end - start)));
}

void loadConfig(const std::string &path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        logWarn("PrismGL", "Config file not found, using defaults.");
        return;
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    const auto content = buffer.str();

    gConfig.targetFps = parseFloat(content, "targetFps", gConfig.targetFps);
    gConfig.minScale = std::clamp(parseFloat(content, "minScale", gConfig.minScale), 0.3f, 1.0f);
    gConfig.maxScale = std::clamp(parseFloat(content, "maxScale", gConfig.maxScale), gConfig.minScale, 1.0f);
    gConfig.shaderCacheBytes = parseBytes(content, "shaderCacheBytes", gConfig.shaderCacheBytes);
}

const Config &getConfig() {
    return gConfig;
}

void setConfig(const Config &config) {
    gConfig = config;
}

} // namespace prismgl
