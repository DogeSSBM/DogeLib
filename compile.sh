#!/bin/sh
printf "\033c"
libraries="-lm -lSDL2 -lSDL2_ttf -lSDL2_gfx -lSDL2_image -lSDL2_net -lSDL2_mixer"
flags="-Wall -Wextra -Wno-missing-braces -O3"
gcc main.c $libraries $flags -o main.out
