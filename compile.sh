#!/bin/bash
printf "\033c"
libraries="-lSDL2 -lSDL2_ttf -lSDL2_image -lm"
flags="-Winline"
gcc main.c $libraries $flags -o main.out
