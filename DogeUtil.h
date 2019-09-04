#pragma once

void clearTerminal(void)
{
	printf("\e[1;1H\e[2J");
}

float randRange(float a, float b)
{
	return ((b-a)*((float)rand()/RAND_MAX))+a;
}

void init_all(uint winXlen, uint winYlen)
{
	gfx_init(winXlen, winYlen);
	img_init();
	text_init();
}

void removeCaps(const char *fileName)
{
	uint fileNameLen = strlen(fileName);
	char fileNameOld[fileNameLen+5];
	memcpy(fileNameOld, fileName, fileNameLen);
	memcpy(&fileNameOld[fileNameLen], ".old", 5);
	if(rename(fileName, fileNameOld)){
		printf("Error renaming %s to %s! Exiting now.\n", fileName, fileNameOld);
		exit(0);
	}
	
}
