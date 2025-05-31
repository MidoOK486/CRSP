#pragma once
#include <crsp/core/opcode_decode.h>

namespace crsp {

void execute_scalar_special(const DecodedOpcode& op);
void execute_scalar_memory(const DecodedOpcode& op);
void execute_scalar_branch(const DecodedOpcode& op);

}
