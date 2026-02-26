#include "prismgl.h"

#include <cstdio>

#if defined(__ANDROID__)
#include <android/log.h>
#endif

namespace prismgl {

void logInfo(const char *tag, const char *message) {
#if defined(__ANDROID__)
    __android_log_print(ANDROID_LOG_INFO, tag, "%s", message);
#else
    std::fprintf(stdout, "[%s] %s\n", tag, message);
#endif
}

void logWarn(const char *tag, const char *message) {
#if defined(__ANDROID__)
    __android_log_print(ANDROID_LOG_WARN, tag, "%s", message);
#else
    std::fprintf(stdout, "[%s] %s\n", tag, message);
#endif
}

void logError(const char *tag, const char *message) {
#if defined(__ANDROID__)
    __android_log_print(ANDROID_LOG_ERROR, tag, "%s", message);
#else
    std::fprintf(stderr, "[%s] %s\n", tag, message);
#endif
}

} // namespace prismgl
