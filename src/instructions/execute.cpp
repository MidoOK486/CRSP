// CRSP/src/instructions/execute.cpp

#include "instructions/execute.h"
#include "instructions/scalar/ADDI.h"
#include "instructions/scalar/ADDIU.h"
#include "instructions/vector/vector_ops.h"
#include "instructions/system/system_ops.h"
#include <stdexcept>

namespace crsp {

void execute_instruction(const DecodedInstruction& instr) {
    switch (instr.op) {
        case 0x00:
            execute_special(instr);
            break;

        case 0x08: // ADDI
            execute_ADDI(instr);
            break;

        case 0x09: // ADDIU
            execute_ADDIU(instr);
            break;

        case 0x0C: // ANDI
        case 0x0D: // ORI
        case 0x0E: // XORI
            execute_scalar(instr);
            break;

        case 0x12: // COP2 Vector Unit
            execute_vector(instr);
            break;

        case 0x3F: // HALT or Reserved
            execute_system(instr);
            break;

        default:
            throw std::runtime_error("Unhandled opcode in execute_instruction");
    }
}

void execute_scalar(const DecodedInstruction& instr) {
    switch (instr.op) {
        case 0x0C: // ANDI
        case 0x0D: // ORI
        case 0x0E: // XORI
            // TODO: Implement these scalar instructions
            throw std::runtime_error("Scalar opcode not yet implemented");
            break;

        default:
            throw std::runtime_error("Unhandled scalar opcode in execute_scalar");
    }
}

void execute_vector(const DecodedInstruction& instr) {
    throw std::runtime_error("Vector instructions not yet implemented");
}

void execute_special(const DecodedInstruction& instr) {
    throw std::runtime_error("SPECIAL instructions not yet implemented");
}

void execute_system(const DecodedInstruction& instr) {
    throw std::runtime_error("System instructions not yet implemented");
}

}
