// CRSP/src/main.cpp

#include "core/rsp_core.h"
#include <iostream>

int main() {
    std::cout << "[CRSP] Starting RSP Execution...\n";

    // Call the main RSP run loop
    crsp::run_cycle();

    std::cout << "[CRSP] RSP Execution Complete.\n";
    return 0;
}
