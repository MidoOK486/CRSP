// CRSP/include/state/rsp_state.h
#pragma once
#include <cstdint>

namespace crsp {

struct RSPState {
    uint32_t gpr[32];    // Scalar general-purpose registers
    uint32_t pc;         // Program counter

    // TODO: Add vector registers, accumulator, flags, etc.
};

extern RSPState rsp_state;

void reset_rsp_state();  // Clears all state to power-on default

}
