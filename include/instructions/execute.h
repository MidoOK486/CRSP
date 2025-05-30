// CRSP/include/instructions/execute.h
#pragma once
#include "decode/decoder.h"

namespace crsp {

// Top-level dispatcher
void execute_instruction(const DecodedInstruction& instr);

// These are implemented in their own files
void execute_scalar(const DecodedInstruction& instr);
void execute_vector(const DecodedInstruction& instr);
void execute_special(const DecodedInstruction& instr);
void execute_system(const DecodedInstruction& instr);

}
