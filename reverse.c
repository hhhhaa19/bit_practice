#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"
void  reverse_string(char* string)
{
	int left = 0;
	int right = strlen(string)-1;
	while (left < right)
	{
		exchange(&string[left], &string[right]);
		left++;
		right--;
	}
}
//recursion
void reverse_string2(char* string)
{
	int len = strlen(string);
	char temp = 0;
	temp = *string;
	if (len == 2)
	{
		exchange(&string[0], &string[1]);
	}
	else
	{
		*string = string[len - 1];
		string[len - 1] = '\0';
		reverse_string2(string + 1);
	}
	string[len - 1] = temp;
}
void re_array(int* arr, int n)
{
	int i;
	for (i = 1; i <= n / 2; i++)
		exchange(&arr[i - 1], &arr[n - i]);
}
void re_str(char str[])
{
	int n = strlen(str);
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		exchange2(&str[left], &str[right]);
		left++;
		right--;
	}
}
void re_sentence(void)
{
	char* arr[1000] = { NULL };//����ÿ�����ʵ��׵�ַ
	int i = 0;//���ӵ��ַ���
	int m = 0;//���ʸ���
	char sen[1000] = { 0 };//���浥������
	int number[10] = { 0 };//ͳ��ÿ�����ʵĸ���
	while ((sen[i] = getchar()) != '.')//���沢�ж�����
	{
		i++;
		(number[m])++;//����
		if (sen[i - 1] == 32)//�õ����ǿո�
		{
			arr[m] = (sen + i) - number[m];//�ҵ�����ĸ�ĵ�ַ
			(number[m])--;//ȥ���ո�
			m++;
		}
	}
	arr[m] = (sen + i) - number[m];
	(number[m])++;//���һ�������Լ����
	for (int i = m; i >= 0; i--)
	{
		for (int j = 0; j < number[i]; j++)
		{
			printf("%c", arr[i][j]);//�����������
		}
		printf(" ");
	}
}
//����һ���������飬ʵ��һ�������������������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�

//����ż��λ������ĺ�벿��

void re_arr(int* arr, int sz)
{
	int i = 0;
	int j = 0;
	//��ѡ�ŵ�˼·���
	for (i = 0; i < sz ; i++)
	{
		for (j = 0; j < sz-1 ; j++)
		{
			if (0==arr[j]%2&&1==arr[j+1]%2)
				exchange2(&arr[j], &arr[j + 1]);
		}
	}
}