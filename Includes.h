#pragma once
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <complex.h>
#include <math.h>
#include <tgmath.h>

#ifdef DOGE_GFX
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#endif
#include "Types.h"
#include "GetInt.h"
#ifdef DOGE_GFX
#include "Colors.h"
#include "Graphics.h"
#endif
#include "Timing.h"
#ifdef DOGE_GFX
#include "Events.h"
#include "Text.h"
#include "Image.h"
#endif
#include "DogeUtil.h"
