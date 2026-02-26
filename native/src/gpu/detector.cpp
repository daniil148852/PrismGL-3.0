#include "utils/logger.h"

#include <string>

namespace prismgl {

enum class GpuFamily {
    Adreno,
    Mali,
    Exynos,
    Unknown
};

GpuFamily detectGpuFamily(const std::string &renderer) {
    const auto lower = std::string(renderer);
    if (lower.find("Adreno") != std::string::npos) {
        return GpuFamily::Adreno;
    }
    if (lower.find("Mali") != std::string::npos) {
        return GpuFamily::Mali;
    }
    if (lower.find("Exynos") != std::string::npos) {
        return GpuFamily::Exynos;
    }
    return GpuFamily::Unknown;
}

void applyGpuProfile(const std::string &renderer) {
    switch (detectGpuFamily(renderer)) {
        case GpuFamily::Adreno:
            logInfo("PrismGL", "Applied Adreno profile.");
            break;
        case GpuFamily::Mali:
            logInfo("PrismGL", "Applied Mali profile.");
            break;
        case GpuFamily::Exynos:
            logInfo("PrismGL", "Applied Exynos profile.");
            break;
        case GpuFamily::Unknown:
        default:
            logWarn("PrismGL", "Using generic GPU profile.");
            break;
    }
}

} // namespace prismgl
