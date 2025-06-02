#pragma once
#include <crsp/core/opcode_decode.h>

namespace crsp {

// Execute SPECIAL group instructions (ADDU, SUBU, SLL, etc.)
void execute_special(const DecodedOpcode& op);

}
