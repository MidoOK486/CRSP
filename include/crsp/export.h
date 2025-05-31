#pragma once

#ifdef _WIN32
  #ifdef CRSP_EXPORTS
    #define CRSP_API __declspec(dllexport)
  #else
    #define CRSP_API __declspec(dllimport)
  #endif
#else
  #define CRSP_API
#endif
