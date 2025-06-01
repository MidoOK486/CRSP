#include "registers.h"
#include <cstring>
#include <cstdio>

namespace crsp {

// 32 General Purpose Registers (GPRs), R4300-compatible
uint32_t GPR[32] = {0};

// Read from register (R0 always returns 0)
uint32_t read_gpr(uint8_t index) {
    if (index == 0) return 0;
    return GPR[index & 0x1F];
}

// Write to register (R0 is hardwired to 0)
void write_gpr(uint8_t index, uint32_t value) {
    if (index == 0) return;
    GPR[index & 0x1F] = value;
}

// Reset all registers to zero
void reset_gprs() {
    std::memset(GPR, 0, sizeof(GPR));
}

}
