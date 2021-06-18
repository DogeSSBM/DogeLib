#pragma once

char* fileReadText(const char *filePath)
{
	if(!strEndsWith(filePath, ".dogelib")){
		printf("Couldnt open file \"%s\"!\n", filePath);
		printf("File must end with \".dogelib\"\n");
		exit(-1);
	}
	File *f = fopen(filePath, "r");
	if(f == NULL){
		printf("Couldnt open file \"%s\"!\n", filePath);
		printf("fopen() returned NULL\n");
		exit(-1);
	}
	fseek(f, 0, SEEK_END);
	const uint len = ftell(f);
	rewind(f);
	char *text = malloc(sizeof(char)*len);
	fread(text, sizeof(char), len, f);
	return text;
}
