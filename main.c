#define DOGE_GFX
#define DOGE_CLI
#include "Includes.h"

int main(int argc, char const *argv[])
{
	#ifdef DOGE_GFX
	init(800, 600);
	setColor(RED);
	fillCircle(400, 300, 100);
	draw();
	while(1){
		events();
		delay(5);
	}
	#else
	init();
	printf("Enter num1\n");
	uint n1 = getInt();
	printf("Enter num2\n");
	uint n2 = getInt();
	printf("Num1 + num2 = %u\n", n1 + n2);
	#endif
	return 0;
}
