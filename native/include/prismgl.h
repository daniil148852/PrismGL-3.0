#pragma once

#include <cstdint>

namespace prismgl {

struct RendererInfo {
    const char *name;
    const char *version;
    const char *glesVersion;
};

struct Config {
    float targetFps = 60.0f;
    float minScale = 0.5f;
    float maxScale = 1.0f;
    std::uint64_t shaderCacheBytes = 512ull * 1024ull * 1024ull;
};

struct FrameMetrics {
    float frameTimeMs = 16.6f;
    float gpuTimeMs = 16.6f;
};

RendererInfo getRendererInfo();
void initialize(const Config &config);
void shutdown();
void updateFrameMetrics(const FrameMetrics &metrics);
float getRenderScale();

} // namespace prismgl
