#pragma once
#include <crsp/core/opcode_decode.h>

namespace crsp {

// Execute ADDIU, LUI, ORI
void execute_scalar_arith(const DecodedOpcode& op);

}
