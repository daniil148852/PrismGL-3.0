#pragma once

#include <cstdint>

namespace prismgl {

struct BatchStats {
    std::uint32_t drawCalls;
    std::uint32_t batches;
};

void beginBatch();
void recordDrawCall();
BatchStats getBatchStats();
void resetBatchStats();

} // namespace prismgl
