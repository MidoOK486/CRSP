#pragma once
#include <cstdint>
#include <crsp/export.h>

namespace crsp {

/// Runs a single RSP cycle (cycle-accurate)
CRSP_API void run_cycle();

/// Optionally: provide access to cycle counter or internal state
CRSP_API uint64_t get_total_cycles();

}
