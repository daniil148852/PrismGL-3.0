#include "utils/logger.h"

#include <cstdint>

namespace prismgl {

struct BatchStats {
    std::uint32_t drawCalls = 0;
    std::uint32_t batches = 0;
};

static BatchStats gStats{};

void beginBatch() {
    gStats.batches += 1;
}

void recordDrawCall() {
    gStats.drawCalls += 1;
}

BatchStats getBatchStats() {
    return gStats;
}

void resetBatchStats() {
    gStats = {};
    logInfo("PrismGL", "Batch statistics reset.");
}

} // namespace prismgl
