#include "opcode_decode.h"
#include <cstdint>

namespace crsp {

DecodedOpcode decode_instruction(uint32_t raw) {
    DecodedOpcode op {};

    op.raw = raw;
    op.opcode = (raw >> 26) & 0x3F;
    op.rs     = (raw >> 21) & 0x1F;
    op.rt     = (raw >> 16) & 0x1F;
    op.rd     = (raw >> 11) & 0x1F;
    op.shamt  = (raw >> 6)  & 0x1F;
    op.funct  = raw & 0x3F;
    op.immediate = raw & 0xFFFF;
    op.address   = raw & 0x03FFFFFF;

    return op;
}

}
