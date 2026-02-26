# PrismGL-3.0

PrismGL-3.0 is a custom Android OpenGL renderer target for Minecraft Java Edition. The repository ships a native translation layer from desktop OpenGL to OpenGL ES 3.x, a shader cache, FPS-focused optimizations, and a small Android registration app for launchers.

## Repository layout

```
.github/workflows/       CI pipeline for APK and native artifacts
android/                 Android registration app
native/                  NDK library (OpenGL → OpenGL ES translation)
launcher-config/         Shared launcher configuration template
docs/                    Architecture and compatibility notes
```

## Key features

- OpenGL 3.2–4.6 call interception and translation to OpenGL ES 3.x
- Shader binary cache for fast warm starts
- Draw call batching, instancing helpers, and bindless texture emulation hooks
- Adaptive rendering with dynamic resolution scaling
- GPU profile detection for Adreno/Mali/Exynos devices
- Shared config registration for PojavLauncher, Zalith, and Amethyst

## Build overview

- Native library: `native/` via CMake/NDK
- Android app: `android/` via Gradle

See `docs/ARCHITECTURE.md` for module details and integration notes.
