#!/bin/bash
printf "\033c"
gcc main.c -lSDL2 -lSDL2_ttf -lSDL2_image -lm -o main.out
