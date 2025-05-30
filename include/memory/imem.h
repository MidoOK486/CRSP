// CRSP/include/memory/imem.h
#pragma once
#include <cstdint>

namespace crsp {

class IMEM {
public:
    IMEM();

    uint32_t read_word(uint32_t addr) const;
    void write_word(uint32_t addr, uint32_t value);

private:
    uint8_t data[0x1000]; // 4KB of instruction memory
};

}
