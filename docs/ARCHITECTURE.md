# PrismGL Architecture

PrismGL is split into a native renderer core and an Android registration app.

## Native library

- `core/`: renderer initialization, dispatcher lifecycle, and state management.
- `gl/`: OpenGL → OpenGL ES translation entry points.
- `shader/`: shader binary caching and source conversion hooks.
- `optimization/`: batching, instancing, and draw-call statistics.
- `render/`: adaptive resolution scaling logic.
- `gpu/`: device profile detection and tuning hooks.

The public API is exposed via `native/include/prismgl.h` and is intentionally minimal so it can be used by launcher or loader integrations.

## Android app

The Android app writes a shared `config.json` file under `/sdcard/PrismGL` for launchers to discover the renderer binary. This keeps the registration mechanism consistent across PojavLauncher, Zalith, and Amethyst.

## Shader cache

Shader binaries are stored under `/sdcard/PrismGL/cache/shaders`. The cache module handles binary reads and writes, leaving compilation details to the OpenGL translation layer.
