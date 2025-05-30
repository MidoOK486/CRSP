// core/rsp_core.cpp
#include "rsp_core.h"
#include "memory/imem.h"
#include "decode/decoder.h"
#include "instructions/execute.h"
#include "timing/cycle_counter.h"

namespace crsp {

void RSP::step_cycle() {
    if (halted) return;

    // Fetch instruction from IMEM (4 bytes)
    uint32_t opcode = imem.read_word(pc);

    // Decode opcode into instruction structure
    DecodedInstruction instr = decode(opcode);

    // Execute instruction (will simulate stalls, timing, etc.)
    execute_instruction(instr);

    // Advance timing model by the correct number of cycles
    cycle_counter.advance(instr.cycles);

    // Move to next instruction (default increment)
    pc += 4;
}

}
