// CRSP/src/instructions/scalar/ADDIU.cpp

#include "instructions/scalar/ADDIU.h"
#include "state/rsp_state.h"
#include <cstdint>

namespace crsp {

void execute_ADDIU(const DecodedInstruction& instr) {
    uint32_t rs_val = rsp_state.gpr[instr.rs];
    uint32_t imm = static_cast<uint16_t>(instr.imm); // zero-extend 16-bit immediate

    uint32_t result = rs_val + imm;
    rsp_state.gpr[instr.rt] = result;
}

}
