#pragma once
#include <cstdint>

namespace crsp {

// Scalar word access
uint32_t memory_read_word(uint32_t addr);
void     memory_write_word(uint32_t addr, uint32_t value);

// Raw memory access
uint8_t* get_dmem_ptr();  // For vector loads/stores
uint8_t* get_imem_ptr();

}
