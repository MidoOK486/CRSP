#include "scalar_opcodes.h"
#include <cstdio>
#include <cstdint>

namespace crsp {

// Internal scalar registers
static int32_t GPR[32] = {0};  // General Purpose Registers

// Helper: Sign extend 16-bit immediate
static inline int32_t sign_extend_16(uint16_t val) {
    return (val & 0x8000) ? (int32_t)(0xFFFF0000 | val) : (int32_t)val;
}

void execute_scalar_special(const DecodedOpcode& op) {
    switch (op.funct) {
        case 0x20: // ADD
            GPR[op.rd] = GPR[op.rs] + GPR[op.rt];
            break;

        case 0x22: // SUB
            GPR[op.rd] = GPR[op.rs] - GPR[op.rt];
            break;

        case 0x24: // AND
            GPR[op.rd] = GPR[op.rs] & GPR[op.rt];
            break;

        case 0x25: // OR
            GPR[op.rd] = GPR[op.rs] | GPR[op.rt];
            break;

        case 0x00: // SLL
            GPR[op.rd] = ((uint32_t)GPR[op.rt]) << op.shamt;
            break;

        case 0x02: // SRL
            GPR[op.rd] = ((uint32_t)GPR[op.rt]) >> op.shamt;
            break;

        case 0x03: // SRA
            GPR[op.rd] = GPR[op.rt] >> op.shamt;
            break;

        default:
            printf("[CRSP] Unknown SPECIAL funct: 0x%02X\n", op.funct);
            break;
    }
}

void execute_scalar_memory(const DecodedOpcode& op) {
    // Placeholder for memory ops
    printf("[CRSP] Memory op (opcode=0x%02X) not yet implemented\n", op.opcode);
}

void execute_scalar_branch(const DecodedOpcode& op) {
    // Placeholder for branch ops
    printf("[CRSP] Branch op (opcode=0x%02X) not yet implemented\n", op.opcode);
}

}
