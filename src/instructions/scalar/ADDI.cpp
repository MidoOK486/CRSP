// CRSP/src/instructions/scalar/ADDI.cpp
#include "instructions/scalar/ADDI.h"
#include "state/rsp_state.h"

namespace crsp {

void execute_ADDI(const DecodedInstruction& instr) {
    int32_t imm = static_cast<int16_t>(instr.immediate); // sign-extend
    uint32_t result = static_cast<int32_t>(rsp_state.gpr[instr.rs]) + imm;

    rsp_state.gpr[instr.rt] = result;

    // Handle r0 always zero
    rsp_state.gpr[0] = 0;
}

}
