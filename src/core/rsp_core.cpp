#include "rsp_core.h"
#include "fetch.h"
#include "opcode_decode.h"
#include "scalar_opcodes.h"
#include "vector_opcodes.h"
#include <cstdio>

namespace crsp {

void run_cycle() {
    // Fetch instruction
    uint32_t raw_instr = fetch_instruction();

    // Decode instruction
    DecodedOpcode decoded = decode_instruction(raw_instr);

    // Dispatch based on major opcode
    switch (decoded.opcode) {
        case 0x00: // SPECIAL (scalar)
            execute_scalar_special(decoded);
            break;

        case 0x08: // ADDI
        case 0x09: // ADDIU
        case 0x0C: // ANDI
        case 0x0D: // ORI
        case 0x0F: // LUI
        case 0x23: // LW
        case 0x2B: // SW
            execute_scalar_memory(decoded);
            break;

        case 0x04: // BEQ
        case 0x05: // BNE
        case 0x06: // BLEZ
        case 0x07: // BGTZ
            execute_scalar_branch(decoded);
            break;

        case 0x12: // COP2
            execute_vector_unit(decoded);
            break;

        default:
            printf("[CRSP] Unknown opcode 0x%02X\n", decoded.opcode);
            break;
    }
}

}
