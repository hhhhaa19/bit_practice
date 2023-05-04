#define _CRT_SECURE_NO_WARNINGS 1
//recursion
int my_strlen(char* string)
{
	if (*string == '\0')
		return 0;
	else
		return 1 + my_strlen(string + 1);
}
//本质指针，解引用
//iteration 
int my_strlen2(char* string)
{
	int count = 0;
	while (string[count] != '\0')
	{
		count++;
	}
	return count;
}