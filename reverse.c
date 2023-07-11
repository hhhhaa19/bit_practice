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
//�����ַ�����������ʼ�ַ��Լ������ַ���ַ
void re_str(char* str, char* end)
{

	while (str < end)
	{
		exchange2(str, end);
		str++;
		end--;
	}
}
void re_sentence(void)
{
	char* arr[1000] = { NULL };//����ÿ�����ʵ��׵�ַ
	int i = 0;//���ӵ��ַ���
	int m = 0;//���ʸ���
	char sen[1000] = { 0 };//���浥������
	int number[10] = { 0 };//ͳ��ÿ�����ʵĸ���
	//gets���Եõ��ַ���
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
//�����������ַ�����������ֲ�����

void re_sentence2(void)
{
	char str[100] = {0};
	gets(str);
	re_str(str, str +strlen(str) - 1);
	char* star = str;
	char* end = str;
	while ('\0'!=*end)
	{
		end++;
		if (*end == ' ')
		{
			re_str(star, end-1);
			star = end+1;
		}
		
	}
	re_str(star, end -1);
	printf("%s", str);
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
//ʵ��һ�����������������ַ����е�k���ַ���
//���磺ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

char* le_string(char* pstr, int k)
//����������ս�����볤��
//��������recursion����ʵ��
{
	if (0 == k)
	{
		return pstr;
	 }
	else
	{
		le_string(strncat(pstr + 1, pstr, 1), k - 1);
	}
}
//��itearation
//����������һ������������ĩβ��'\0'������
void le_string2(char* pstr, int k, int len)
{
	int i, j;
	char temp[100];
	for (j = 0; j < k; j++)
	{
		temp[j] = pstr[j];
	}
	for (j = 0; j < k; j++)
	{
		for (i = 0; i < k-j ;i++)//���ƴ���
		{
		*(pstr + i) = *(pstr + i + 1);
		}
	}
	for (j = 0; j < k; j++)
	{
		pstr[j+len-k] = temp[j];
	}
}

//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����


/*�磺����s1 = AABCD��s2 = BCDAA������1

����s1 = abcd��s2 = ACBD������0.*/
int is_le_str(char* pstr, char* tag, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		char* ans = le_string(pstr, i);
		if (0==strcmp(tag,ans))
		{
			return 1;
		}
	}
	return 0;
}