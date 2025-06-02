#include "rsp_core.h"
#include "fetch.h"
#include "opcode_decode.h"
#include "execute_scalar.h"
#include "scalar_arith.h"
#include "scalar_branch.h"
#include "scalar_memory.h"
#include "registers.h"

#include <cstdio>

namespace crsp {

void run_cycle() {
    uint32_t pc = get_pc();
    uint32_t raw = fetch_instruction(pc);
    DecodedOpcode decoded = decode_opcode(raw);

    // Print debug info (optional)
    // printf("[CRSP] PC: 0x%04X | Raw: 0x%08X | Opcode: 0x%02X\n", pc, raw, decoded.opcode);

    switch (decoded.opcode) {
        // SPECIAL opcodes (e.g., ADDU, SUBU, AND, OR...) not yet handled
        case 0x00:
            execute_special(decoded);
            break;

        // Immediate arithmetic/logical
        case 0x09: // ADDIU
        case 0x0F: // LUI
        case 0x0D: // ORI
            execute_scalar_arith(decoded);
            break;

        // Branches
        case 0x04: // BEQ
        case 0x05: // BNE
        case 0x06: // BLEZ
        case 0x07: // BGTZ
            execute_scalar_branch(decoded);
            break;

        // Memory load/store
        case 0x23: // LW
        case 0x2B: // SW
            execute_scalar_memory(decoded);
            break;

        // TODO: COP0, COP2, SPECIAL2, VU ops...

        default:
            printf("[CRSP] Unknown opcode: 0x%02X at PC 0x%04X\n", decoded.opcode, pc);
            break;
    }

    // Increment PC (for now, no delay slot or branching control logic)
    increment_pc();
}

}
