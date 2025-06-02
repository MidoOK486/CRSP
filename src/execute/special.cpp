#include "special.h"
#include "registers.h"
#include <cstdint>
#include <cstdio>

namespace crsp {

void execute_special(const DecodedOpcode& op) {
    uint32_t rs = read_gpr(op.rs);
    uint32_t rt = read_gpr(op.rt);
    uint32_t result = 0;

    switch (op.funct) {
        case 0x21: // ADDU
            result = rs + rt;
            write_gpr(op.rd, result);
            break;

        case 0x23: // SUBU
            result = rs - rt;
            write_gpr(op.rd, result);
            break;

        case 0x24: // AND
            result = rs & rt;
            write_gpr(op.rd, result);
            break;

        case 0x25: // OR
            result = rs | rt;
            write_gpr(op.rd, result);
            break;

        case 0x26: // XOR
            result = rs ^ rt;
            write_gpr(op.rd, result);
            break;

        case 0x27: // NOR
            result = ~(rs | rt);
            write_gpr(op.rd, result);
            break;

        case 0x00: // SLL
            result = rt << op.shamt;
            write_gpr(op.rd, result);
            break;

        case 0x02: // SRL
            result = rt >> op.shamt;
            write_gpr(op.rd, result);
            break;

        case 0x03: // SRA
            result = static_cast<int32_t>(rt) >> op.shamt;
            write_gpr(op.rd, result);
            break;

        case 0x2A: // SLT
            result = (static_cast<int32_t>(rs) < static_cast<int32_t>(rt)) ? 1 : 0;
            write_gpr(op.rd, result);
            break;

        case 0x2B: // SLTU
            result = (rs < rt) ? 1 : 0;
            write_gpr(op.rd, result);
            break;

        default:
            printf("[CRSP] Unknown SPECIAL funct: 0x%02X\n", op.funct);
            break;
    }
}

}
