// CRSP/src/core/rsp_core.cpp

#include "core/rsp_core.h"
#include "decode/decoder.h"
#include "instructions/execute.h"
#include "memory/imem.h"
#include "state/rsp_state.h"
#include "timing/cycle_counter.h"
#include <iostream>

namespace crsp {

void run_cycle() {
    // Reset the RSP state before starting execution
    reset_rsp_state();

    while (true) {
        // Fetch 32-bit instruction from IMEM at current PC
        uint32_t raw_instr = fetch_instruction(rsp_state.pc);

        // Decode the instruction
        DecodedInstruction instr = decode_instruction(raw_instr);

        // Execute the instruction
        try {
            execute_instruction(instr);
        } catch (const std::exception& e) {
            std::cerr << "Execution error at PC 0x"
                      << std::hex << rsp_state.pc << ": " << e.what() << std::endl;
            break;
        }

        // Advance PC to next instruction (4 bytes)
        rsp_state.pc += 4;

        // Advance cycle counter (this will eventually vary per instruction)
        cycle_counter.advance(1);

        // Example stop condition (in real RSP, HALT or signal would do this)
        if (rsp_state.pc >= 0x1000) {
            break;
        }
    }
}

}
