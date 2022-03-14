#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int charToInt(const char c)
{
	if(c < '0' || c > '9')
		return 0;
	else
		return (int)c - '0';
}

int shiftL(int num, int digits)
{
	if(digits <= 0){
		return num;
	}
	else{
		for(int i = 1; i < digits; i++){
			num *= 10;
		}
	}
	return num;
}

int strToInt(const char *str)
{
	int total = 0;
	int current = 0;
	for(int i = strlen(str); i >= 0; i--){
		total += shiftL(charToInt(str[i]), current);
		current++;
	}
	return total;
}

int shiftR(const int num)
{
	return num / 10;
}

int getR(const int num)
{
	return num % 10;
}

char intToChar(const int num)
{
	if(num > 9 || num < 0)
		return '0';
	else
		return (char)(num + '0');
}

void intToStr(int num, char* str)
{
	for(int i = strlen(str); i > 0 && num > 0; i--){
		str[i-1] = intToChar(getR(num));
		num = shiftR(num);
	}
}

int getInt(void)
{
	const static int bufSize = 10;
	char buffer[bufSize];
	memset(buffer, '\0', bufSize);
	for(int i = 0; i < bufSize - 1; i++){
		buffer[i] = getchar();
		if(buffer[i] == '\n'){
			buffer[i] = '\0';
			if(i == 0)
				return 0;
			else
				return strToInt(buffer);
		}
	}
	if(getchar()!='\n'){
		printf("\nNumber too large, using [%s] to prevent stack overflow!\n", buffer);
		while(getchar() != '\n');
	}
	return strToInt(buffer);
}
