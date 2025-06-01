#include "memory_interface.h"
#include <cstring>
#include <cstdio>

namespace crsp {

// 4KB each for Data Memory (DMEM) and Instruction Memory (IMEM)
static uint8_t DMEM[0x1000] = {0};
static uint8_t IMEM[0x1000] = {0};

void memory_write_word(uint32_t addr, uint32_t value) {
    if (addr >= 0x0000 && addr <= 0x0FFC) {
        std::memcpy(&DMEM[addr], &value, sizeof(uint32_t));
    } else {
        printf("[CRSP] Invalid write addr: 0x%08X\n", addr);
    }
}

uint32_t memory_read_word(uint32_t addr) {
    if (addr >= 0x0000 && addr <= 0x0FFC) {
        uint32_t value;
        std::memcpy(&value, &DMEM[addr], sizeof(uint32_t));
        return value;
    } else {
        printf("[CRSP] Invalid read addr: 0x%08X\n", addr);
        return 0;
    }
}

uint8_t* get_dmem_ptr() {
    return DMEM;
}

uint8_t* get_imem_ptr() {
    return IMEM;
}

}
