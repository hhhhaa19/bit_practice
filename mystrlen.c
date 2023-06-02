#define _CRT_SECURE_NO_WARNINGS 
#include "main.h"
//recursion
int my_strlen(const char* string)
{
	assert(string != NULL);
	if (*string)
		return  1 + my_strlen(string + 1);
	else
		return 0;
}
//本质指针，解引用
//iteration 
int my_strlen2(const char* string)
{
	assert(string != NULL);
	int count = 0;
	while (string[count++]);
	return count-1;
}