#!/bin/bash
printf "\033c"
libraries="-lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_net -lm"
flags="-O3 -Winline"
gcc main.c $libraries $flags -o main.out
