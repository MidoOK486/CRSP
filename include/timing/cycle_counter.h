// CRSP/include/timing/cycle_counter.h
#pragma once
#include <cstdint>

namespace crsp {

class CycleCounter {
public:
    CycleCounter();

    void reset();
    void advance(int cycles);
    uint64_t current() const;

private:
    uint64_t total_cycles;
};

extern CycleCounter cycle_counter;

}
