#define _CRT_SECURE_NO_WARNINGS 1
//模拟实现strlen
//指针剪指针
#include"main.h"
size_t my_strlen3(const char* str)
{
	char* sta = str;
	assert(str != NULL);
	while (*str != '\0')
	{
		str++;
	}
	return str - sta;
	
}
size_t my_strlen(const char* string)
{
	assert(string != NULL);
	if (*string)
		return  1 + my_strlen(string + 1);
	else
		return 0;
}
//本质指针，解引用
//iteration 
size_t my_strlen2(const char* string)
{
	assert(string != NULL);
	int count = 0;
	while (string[count++]);
	return count - 1;
}


//strcpy
char* my_strcat(char* dest, const char* sou)
{
	assert(dest && sou);
	char* start=dest; 
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *sou++)
	{
		;
	}
	return start;
}
//strcmp
int my_strcmp(const char* str, const char* str2)
{
	while (*str == *str2&&*str&&*str2)
	{
		str++;
		str2++;
	}
	return *str - *str2;
}

//strcay
char* my_strcpy(char* destination, const char* source)
{
	char* start = *destination;
	while (*destination++=*source++)
	{
		;
	}
	return start;
}
//strstr

char* my_strstr( char* str1, char* str2)
{
	
	while (*str1)
	{
		
		char* temp = str1;
		char* temp2 = str2;
		while (*temp2 == *temp&& *temp2 && *temp)
		{
			temp2++;
			temp++;
		}
		if (*temp2== '\0')
			return str1;

		str1++;
	}
	return NULL;
}