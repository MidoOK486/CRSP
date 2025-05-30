// CRSP/src/state/rsp_state.cpp
#include "state/rsp_state.h"
#include <cstring> // for memset

namespace crsp {

// Global RSP state instance
RSPState rsp_state;

void reset_rsp_state() {
    std::memset(&rsp_state, 0, sizeof(RSPState));
    rsp_state.pc = 0x0000; // RSP starts executing at 0x0000 in IMEM
}

}
