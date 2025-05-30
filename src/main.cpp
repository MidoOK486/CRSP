// CRSP/src/main.cpp

#include "core/rsp_core.h"
#include "main.h"
#include <iostream>

int main() {
    std::cout << "[CRSP] Initializing...\n";
    crsp::initialize_crsp();

    std::cout << "[CRSP] Starting RSP Execution...\n";
    crsp::run_cycle();

    std::cout << "[CRSP] Shutting down...\n";
    crsp::shutdown_crsp();

    return 0;
}

namespace crsp {

void initialize_crsp() {
    // In the future: load IMEM, set PC, config logging
    std::cout << "[CRSP] System initialized.\n";
}

void shutdown_crsp() {
    // In the future: save logs, clean state, etc.
    std::cout << "[CRSP] System shutdown complete.\n";
}

}
