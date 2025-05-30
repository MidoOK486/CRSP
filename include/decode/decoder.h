// CRSP/include/decode/decoder.h
#pragma once
#include <cstdint>

namespace crsp {

struct DecodedInstruction {
    uint32_t opcode;

    uint8_t op;
    uint8_t rs;
    uint8_t rt;
    uint8_t rd;
    uint8_t sa;
    uint8_t func;
    uint16_t immediate;
    uint32_t address;

    int cycles; // default cycle cost (1 or overridden later)
};

DecodedInstruction decode(uint32_t opcode);

}
