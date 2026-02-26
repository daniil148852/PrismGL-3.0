#pragma once

#include "prismgl.h"

#include <string>

namespace prismgl {

void loadConfig(const std::string &path);
const Config &getConfig();
void setConfig(const Config &config);

} // namespace prismgl
