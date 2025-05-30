// CRSP/src/decode/decoder.cpp
#include "decode/decoder.h"

namespace crsp {

DecodedInstruction decode(uint32_t opcode) {
    DecodedInstruction instr{};
    instr.opcode = opcode;

    instr.op = (opcode >> 26) & 0x3F;
    instr.rs = (opcode >> 21) & 0x1F;
    instr.rt = (opcode >> 16) & 0x1F;
    instr.rd = (opcode >> 11) & 0x1F;
    instr.sa = (opcode >> 6)  & 0x1F;
    instr.func = opcode & 0x3F;
    instr.immediate = opcode & 0xFFFF;
    instr.address = opcode & 0x03FFFFFF;

    // Cycle estimate (default — real logic can override)
    instr.cycles = 1;

    return instr;
}

}
