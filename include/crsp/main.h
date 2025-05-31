#pragma once
#include <crsp/export.h>

#ifdef __cplusplus
extern "C" {
#endif

/// Initializes the CRSP RSP plugin. Should be called once at emulator startup.
CRSP_API void crsp_plugin_init();

/// Runs the RSP for a full frame or execution cycle as needed by the emulator.
CRSP_API void crsp_run_frame();

#ifdef __cplusplus
}
#endif
