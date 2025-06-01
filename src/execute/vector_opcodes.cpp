#include "vector_opcodes.h"
#include <cstdio>
#include <cstdint>

namespace crsp {

// Vector registers (8 vector registers, each 128-bit = 8 x int16_t)
static int16_t VR[8][8] = {0};

// Execute a COP2 vector instruction
void execute_vector_unit(const DecodedOpcode& op) {
    // For now, just print the raw opcode fields
    printf("[CRSP] COP2 Vector instruction opcode: 0x%02X funct: 0x%02X\n", op.opcode, op.funct);

    // TODO: Implement vector instruction decoding & execution
}

}
