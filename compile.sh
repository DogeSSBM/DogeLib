#!/bin/sh
printf "\033c"
libraries="-lSDL2 -lSDL2_ttf -lSDL2_gfx -lSDL2_image"
flags="-Wall -Wno-missing-braces -lm"
gcc main.c $libraries $flags -o main.out
