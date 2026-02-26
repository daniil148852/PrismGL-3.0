#pragma once

#include <string>

namespace prismgl {

enum class GpuFamily {
    Adreno,
    Mali,
    Exynos,
    Unknown
};

GpuFamily detectGpuFamily(const std::string &renderer);
void applyGpuProfile(const std::string &renderer);

} // namespace prismgl
