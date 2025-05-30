// CRSP/src/memory/imem.cpp
#include "memory/imem.h"
#include <cstring>
#include <stdexcept>

namespace crsp {

IMEM::IMEM() {
    std::memset(data, 0, sizeof(data));
}

uint32_t IMEM::read_word(uint32_t addr) const {
    if (addr % 4 != 0 || addr >= 0x1000) {
        throw std::runtime_error("IMEM read_word: unaligned or out-of-bounds");
    }

    return (data[addr] << 24) |
           (data[addr + 1] << 16) |
           (data[addr + 2] << 8) |
           (data[addr + 3]);
}

void IMEM::write_word(uint32_t addr, uint32_t value) {
    if (addr % 4 != 0 || addr >= 0x1000) {
        throw std::runtime_error("IMEM write_word: unaligned or out-of-bounds");
    }

    data[addr]     = (value >> 24) & 0xFF;
    data[addr + 1] = (value >> 16) & 0xFF;
    data[addr + 2] = (value >> 8) & 0xFF;
    data[addr + 3] = value & 0xFF;
}

}
