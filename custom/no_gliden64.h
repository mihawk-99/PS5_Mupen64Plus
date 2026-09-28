/* Mupen64Plus-Next without GLideN64 (HAVE_GLIDEN64=0): what the libretro glue
 * takes from glsm, with no OpenGL headers. ParaLLEl-RDP and Angrylion render;
 * plugin_connect_rdp_api turns a request for GLideN64 into one of them, so
 * none of this is reached with GLideN64 selected. */
#ifndef M64P_NO_GLIDEN64_H
#define M64P_NO_GLIDEN64_H

#include <stdbool.h>
#include <libretro.h>
#include <glsm/glsm_state_ctl.h>

typedef bool (*glsm_framebuffer_lock)(void *);

typedef struct glsm_ctx_params
{
   glsm_framebuffer_lock framebuffer_lock;
   retro_hw_context_reset_t context_reset;
   retro_hw_context_reset_t context_destroy;
   retro_environment_t environ_cb;
   bool stencil;
   unsigned major;
   unsigned minor;
} glsm_ctx_params_t;

#endif
