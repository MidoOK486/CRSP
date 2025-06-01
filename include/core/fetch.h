#pragma once
#include <cstdint>

namespace crsp {

// Fetch 32-bit instruction from IMEM at current PC
uint32_t fetch_instruction();

// RSP PC access
uint32_t get_pc();
void     set_pc(uint32_t value);

}
