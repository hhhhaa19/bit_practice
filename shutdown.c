#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"main.h"
void shutdown(void)
{
	char text[20] = { 0 };
	system("shutdown -s -t 120");
	printf("your computer is going to shutdown unless you input 'you'\n");
	do
	{
		scanf("%s", text);

	} while (0 != strcmp(text, "you"));//strcmp 不能有空格
	system("shutdown -a");
}