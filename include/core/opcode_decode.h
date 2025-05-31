#pragma once
#include <cstdint>

namespace crsp {

struct DecodedOpcode {
    uint32_t raw;
    uint8_t opcode;
    uint8_t rs, rt, rd, shamt, funct;
    uint16_t immediate;
    uint32_t address;
};

DecodedOpcode decode_instruction(uint32_t raw);

}
