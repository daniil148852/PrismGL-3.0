cmake_minimum_required(VERSION 3.22)

project(prismgl LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(prismgl SHARED
    src/core/context.cpp
    src/core/dispatcher.cpp
    src/gl/translator.cpp
    src/shader/cache.cpp
    src/optimization/batcher.cpp
    src/render/adaptive.cpp
    src/gpu/detector.cpp
    src/utils/config.cpp
    src/utils/logger.cpp
)

target_include_directories(prismgl PUBLIC include)

target_compile_definitions(prismgl PRIVATE PRISMGL_VERSION=\"3.0.0\")
