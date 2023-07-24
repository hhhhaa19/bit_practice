#define _CRT_SECURE_NO_WARNINGS 1
//ģ��ʵ��strlen
//ָ���ָ��
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
//����ָ�룬������
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

//memcpy
void* my_memcpy(void* des, const void* sou, size_t num)
{
	void* st = des;
	while (num--)
	{
		*(char*)des = *(char*)sou;
		des = (char*)des + 1;
		sou = (char*)sou + 1;
	}
	return st;
}
//memmove
void* my_memmove(void* des, const void* sou, size_t num)
{
	void* st = des;
	if (des < sou)
	{
		while (num--)
		{
			*(char*)des = *(char*)sou;
			des = (char*)des + 1;
			sou = (char*)sou + 1;
		}
	}
	else
	{
		while (num)
		{
			*((char*)des + num - 1) = *((char*)sou + num - 1);
			num--;
		}
	}
	return st;
}
//metset
//strtok


//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�

//��дһ�������ҳ�������ֻ����һ�ε����֡�
//���磺
//�������Ԫ���ǣ�1��2��3��4��5��1��2��3��4��6
//ֻ��5��6ֻ����1�Σ�Ҫ�ҳ�5��6.



//strncpy
char* my_strncpy(char* destination, const char* source, size_t num)
{
	int i = 0;
	assert(destination && source);
	for (i = 0; i < num; i++)
	{
		*(destination + i) = *(source + i);
	}
	return destination;
}
char* my_strncat(char* destination, const char* source, size_t num)
{
	int i = 0;
	assert(destination && source);
	int len = strlen(destination);
	for (i = 0; i <num; i++)
	{
		*(destination + len + i) = *(source + i);
	}

	return destination;
}

//atoi
int my_atoi(const char* str)
{
	int len = strlen(str);
	int ret = 0;
	int flag = 1;
	for (int i = 0; i <len; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			ret = (int)str[i]- 48+ ret * 10;//ǽש��Acsll
		}
		else if (str[i] == '-')
		{
			flag = -1;
		}
	}
	return ret*flag;
}
