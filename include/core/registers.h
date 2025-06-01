#pragma once
#include <cstdint>

namespace crsp {

// GPR access
uint32_t read_gpr(uint8_t index);
void     write_gpr(uint8_t index, uint32_t value);

// Reset all GPRs
void     reset_gprs();

// Global register array (for direct access if needed)
extern uint32_t GPR[32];

}
