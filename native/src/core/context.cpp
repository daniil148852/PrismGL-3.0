#include "prismgl.h"
#include "utils/config.h"
#include "utils/logger.h"

#include <atomic>

namespace prismgl {

static std::atomic<bool> gInitialized{false};
static float gRenderScale = 1.0f;

RendererInfo getRendererInfo() {
    return RendererInfo{"PrismGL", PRISMGL_VERSION, "OpenGL ES 3.2"};
}

void initialize(const Config &config) {
    if (gInitialized.exchange(true)) {
        return;
    }
    setConfig(config);
    gRenderScale = config.maxScale;
    logInfo("PrismGL", "Renderer initialized.");
}

void shutdown() {
    if (!gInitialized.exchange(false)) {
        return;
    }
    logInfo("PrismGL", "Renderer shutdown.");
}

void updateRenderScale(float scale) {
    gRenderScale = scale;
}

float getRenderScale() {
    return gRenderScale;
}

} // namespace prismgl
