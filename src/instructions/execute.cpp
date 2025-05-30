// CRSP/src/instructions/execute.cpp
#include "instructions/execute.h"
#include "instructions/scalar/scalar_ops.h"
#include "instructions/vector/vector_ops.h"
#include "instructions/system/system_ops.h"

namespace crsp {

void execute_instruction(const DecodedInstruction& instr) {
    switch (instr.op) {
        case 0x00:
            // SPECIAL opcode group — check func
            execute_special(instr);
            break;

        case 0x08: // ADDI
        case 0x09: // ADDIU
        case 0x0C: // ANDI
        case 0x0D: // ORI
        case 0x0E: // XORI
            execute_scalar(instr);
            break;

        case 0x20: // LB/LW
        case 0x28: // SB/SW
            execute_scalar(instr);
            break;

        case 0x12: // COP2 (Vector unit)
            execute_vector(instr);
            break;

        case 0x3F: // HALT or reserved
            execute_system(instr);
            break;

        default:
            // Unsupported opcode
            throw std::runtime_error("Unhandled opcode in execute_instruction");
    }
}

}
