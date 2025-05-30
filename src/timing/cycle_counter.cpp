// CRSP/src/timing/cycle_counter.cpp
#include "timing/cycle_counter.h"

namespace crsp {

CycleCounter::CycleCounter() : total_cycles(0) {}

void CycleCounter::reset() {
    total_cycles = 0;
}

void CycleCounter::advance(int cycles) {
    total_cycles += cycles;
}

uint64_t CycleCounter::current() const {
    return total_cycles;
}

}
