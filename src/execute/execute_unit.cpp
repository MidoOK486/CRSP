#include "execute_unit.h"
#include "scalar_opcodes.h"
#include "vector_opcodes.h"
#include <cstdio>

namespace crsp {

void execute_instruction(const DecodedOpcode& op) {
    switch (op.opcode) {
        case 0x00: // SPECIAL (scalar instructions using funct)
            execute_scalar_special(op);
            break;

        case 0x20: // LB
        case 0x21: // LH
        case 0x23: // LW
        case 0x24: // LBU
        case 0x25: // LHU
        case 0x28: // SB
        case 0x29: // SH
        case 0x2B: // SW
            execute_scalar_memory(op);
            break;

        case 0x04: // BEQ
        case 0x05: // BNE
        case 0x06: // BLEZ
        case 0x07: // BGTZ
            execute_scalar_branch(op);
            break;

        case 0x12: // COP2 (Vector Unit)
            execute_vector_unit(op);
            break;

        default:
            printf("[CRSP] Unhandled opcode: 0x%02X\n", op.opcode);
            break;
    }
}

}
