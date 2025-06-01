#include "fetch.h"
#include "memory_interface.h"
#include <cstdint>
#include <cstdio>

namespace crsp {

// RSP program counter (PC)
static uint32_t PC = 0x0000;

uint32_t get_pc() {
    return PC;
}

void set_pc(uint32_t value) {
    PC = value & 0xFFF;  // Mask to 4KB IMEM range
}

uint32_t fetch_instruction() {
    if (PC > 0x0FFC) {
        printf("[CRSP] PC out of bounds: 0x%04X\n", PC);
        return 0;
    }

    const uint8_t* imem = get_imem_ptr();
    uint32_t instr;
    std::memcpy(&instr, imem + PC, sizeof(uint32_t));
    PC += 4;  // Advance to next instruction
    return instr;
}

}
