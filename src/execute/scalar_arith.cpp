#include "scalar_arith.h"
#include "registers.h"
#include <cstdint>
#include <cstdio>

namespace crsp {

void execute_scalar_arith(const DecodedOpcode& op) {
    uint32_t rs_val = read_gpr(op.rs);
    uint32_t result = 0;
    uint32_t imm    = static_cast<int16_t>(op.immediate); // sign-extend

    switch (op.opcode) {
        case 0x09: // ADDIU
            result = rs_val + imm;
            write_gpr(op.rt, result);
            break;

        case 0x0F: // LUI
            result = op.immediate << 16;
            write_gpr(op.rt, result);
            break;

        case 0x0D: // ORI
            result = rs_val | (op.immediate & 0xFFFF);
            write_gpr(op.rt, result);
            break;

        default:
            printf("[CRSP] Unknown scalar arith opcode: 0x%02X\n", op.opcode);
            break;
    }
}

}
