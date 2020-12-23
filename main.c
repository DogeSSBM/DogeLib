#include "Includes.h"

int main(int argc, char const *argv[])
{
	const Length window = {800, 600};
	init(window);
	setFontSize(48);

	for(uint i = 0; i < 100; i++){
		int n = randRange(-20, 20);
		int min = randRange(-99, 99);
		int max = randRange(-99, 99);

		int err = 0;
		int ans = n;
		int size = abs(min-max);
		if(!inBound(n, min, max)){
			if(n < min){
				err = abs(min-n);
				err %= size;
				ans = max-err;
			}else{
				err = abs(n-max);
				err %= size;
				ans = min+err;
			}
		}else{
			ans = n;
		}

		printf("%s wrap(% 2d, % 2d, % 2d) = % 2d\nans = % 2d\n\n",
			n==ans?"PASSED":"FAILED",n, min, max, wrap(n, min, max), ans);

	}
	printf("\n");

	while(1){
		Ticks frameStart = getTicks();
		clear();

		draw();
		events(frameStart + TPF);
	}
	return 0;
}
