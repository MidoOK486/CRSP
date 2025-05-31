#pragma once

#ifdef _WIN32
  #ifdef CRSP_EXPORTS
    #define CRSP_API __declspec(dllexport)
  #else
    #define CRSP_API __declspec(dllimport)
  #endif
#else
  #define CRSP_API __attribute__((visibility("default")))
#endif

namespace crsp {

// Exported public API
CRSP_API void run_cycle();

}
