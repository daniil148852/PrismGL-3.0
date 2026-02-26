#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace prismgl {

void setShaderCacheRoot(const std::string &path);
std::string getShaderCachePath(const std::string &hash);
bool loadShaderBinary(const std::string &hash, std::vector<std::uint8_t> &outData);
bool storeShaderBinary(const std::string &hash, const std::vector<std::uint8_t> &data);

} // namespace prismgl
