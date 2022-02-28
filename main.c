#include "Includes.h"

void pi(const int a, const int b, const int n)
{
    printf("i (%d, %d)\n", a, b);
    for(uint i = 0; i < n; i++){
        printf("\t%d\n", randRange(a, b));
    }
    for(uint i = 0; i < 1000; i++){
        const int j = randRange(a, b);
        const int min = mini(a, b);
        const int max = maxi(a, b);
        if(j < min || j >= max){
            printf("Error: %d not in range (%d, %d)\n", j, min, max);
        }
    }
}

void pf(const float a, const float b, const int n)
{
    printf("f (%f, %f)\n", a, b);
    for(uint i = 0; i < n; i++){
        printf("\t%f\n", randRangef(a, b));
    }
    for(uint i = 0; i < 1000; i++){
        const float j = randRangef(a, b);
        const float min = minf(a, b);
        const float max = maxf(a, b);
        if(j < min || j >= max){
            printf("Error: %f not in range (%f, %f)\n", j, min, max);
        }
    }
}

int main(int argc, char const *argv[])
{
    init(800, 600);

    pf(0.0f, 100.0f, 10);
    pf(-100.0f, 100.0f, 10);
    pf(100.0f, -100.0f, 10);
    pf(-100.0f, 0.0f, 10);
    pf(0.0f, 0.1f, 10);

    while(1){
        const Ticks time = frameStart();

        if(keyState(SDL_SCANCODE_ESCAPE))
            exit(0);

        frameEnd(time);
	}
	return 0;
}
