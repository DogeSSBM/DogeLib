#!/bin/sh
printf "\033c"
libraries="-lSDL2 -lSDL2_ttf -lSDL2_gfx -lSDL2_image -lSDL2_net -lSDL2_mixer"
flags="-Wall -Wno-missing-braces -lm -O3 -Winline"
gcc main.c $libraries $flags -o main.out
