#include "scalar_branch.h"
#include "fetch.h"
#include <cstdio>
#include <cstdint>

namespace crsp {

// Temporary scalar GPRs (simulate 32 general-purpose registers)
extern uint32_t GPR[32];

// Internal helper: sign-extend 16-bit immediate
static inline int32_t sign_extend_imm16(uint16_t imm) {
    return static_cast<int16_t>(imm);
}

void execute_scalar_branch(const DecodedOpcode& op) {
    uint32_t pc = get_pc();
    int32_t offset = sign_extend_imm16(op.immediate) << 2;

    switch (op.opcode) {
        case 0x04: // BEQ
            if (GPR[op.rs] == GPR[op.rt])
                set_pc(pc + offset);
            break;

        case 0x05: // BNE
            if (GPR[op.rs] != GPR[op.rt])
                set_pc(pc + offset);
            break;

        case 0x06: // BLEZ
            if (static_cast<int32_t>(GPR[op.rs]) <= 0)
                set_pc(pc + offset);
            break;

        case 0x07: // BGTZ
            if (static_cast<int32_t>(GPR[op.rs]) > 0)
                set_pc(pc + offset);
            break;

        default:
            printf("[CRSP] Unknown branch opcode: 0x%02X\n", op.opcode);
            break;
    }

    // Note: Delay slots not yet handled; will be cycle-accurate later
}

}
