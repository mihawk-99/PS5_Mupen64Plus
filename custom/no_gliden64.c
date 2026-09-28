/* The GLideN64 and glsm entry points the libretro glue calls, for a build
 * without GLideN64 (HAVE_GLIDEN64=0). Nothing selects GLideN64 there, so each
 * one only has to exist; glsm_ctl reports that there is no GL state. */
#include "no_gliden64.h"

bool glsm_ctl(enum glsm_state_ctl state, void *data)
{
   (void)state;
   (void)data;
   return false;
}

void gln64_thr_gl_invoke_command_loop(void) {}
void gln64DestroyGfxContext(void) {}
void gln64ReinitGfxContext(void) {}

/* GLideN64 reads its configuration here; there is none to read. */
void Config_LoadConfig(void) {}

/* libretro.c's shutdown loop waits on this only for GLideN64's GL thread. */
bool threaded_gl_safe_shutdown = true;

/* The RSP's memories as cxd4 (mupen64plus-rsp-cxd4/su.h) declares them. With
 * GLideN64 built, its N64.cpp defines these two, and cxd4 links to them. */
unsigned char *DMEM;
unsigned char *IMEM;
