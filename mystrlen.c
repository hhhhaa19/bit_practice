#define _CRT_SECURE_NO_WARNINGS 1
//recursion
int my_strlen(char* string)
{
	if (string == '/0')
		return 0;
	else
		return 1 + my_strlen(string + 1);
}