#include "scalar_memory.h"
#include "registers.h"
#include "memory_interface.h"
#include <cstdio>
#include <cstdint>

namespace crsp {

void execute_scalar_memory(const DecodedOpcode& op) {
    uint32_t base   = read_gpr(op.rs);
    uint32_t offset = static_cast<int16_t>(op.immediate);  // sign-extended
    uint32_t addr   = base + offset;

    switch (op.opcode) {
        case 0x23: { // LW (Load Word)
            uint32_t value = memory_read_word(addr);
            write_gpr(op.rt, value);
            break;
        }

        case 0x2B: { // SW (Store Word)
            uint32_t value = read_gpr(op.rt);
            memory_write_word(addr, value);
            break;
        }

        default:
            printf("[CRSP] Unknown scalar memory opcode: 0x%02X\n", op.opcode);
            break;
    }
}

}
