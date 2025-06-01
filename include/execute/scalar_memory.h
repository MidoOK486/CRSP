#pragma once
#include <crsp/core/opcode_decode.h>

namespace crsp {

// Execute scalar memory instructions (LW, SW)
void execute_scalar_memory(const DecodedOpcode& op);

}
