#include "prismgl.h"
#include "core/context.h"
#include "utils/config.h"

#include <algorithm>

namespace prismgl {

void updateFrameMetrics(const FrameMetrics &metrics) {
    const auto &config = getConfig();
    const float targetFrameMs = 1000.0f / std::max(config.targetFps, 1.0f);
    float scaleDelta = 0.0f;

    if (metrics.frameTimeMs > targetFrameMs * 1.1f) {
        scaleDelta = -0.05f;
    } else if (metrics.frameTimeMs < targetFrameMs * 0.9f) {
        scaleDelta = 0.05f;
    }

    float nextScale = std::clamp(getRenderScale() + scaleDelta, config.minScale, config.maxScale);
    updateRenderScale(nextScale);
}

} // namespace prismgl
