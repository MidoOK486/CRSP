#pragma once
#include <crsp/core/opcode_decode.h>

namespace crsp {

// Execute scalar branching instructions (BEQ, BNE, etc.)
void execute_scalar_branch(const DecodedOpcode& op);

}
