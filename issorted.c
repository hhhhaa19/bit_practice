#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//�ж������Ƿ�����
//˼·һ����ð�ݵ���ʽ����
void is_sorted (void) 
{

    int a;

    int i = 0;

    int arr[51] = { 0 };

    scanf("%d", &a);

    for (i = 0; i < a; i++)

    {

        scanf("%d ", &arr[i]);

    }

    int flag1 = 1;

    int flag2 = 1;

    i = 0;

    int j = 0;

    for (i = 0; i < a; i++)

    {
        for (j = 0; j < a - i - 1; j++)

        {

            if (arr[j] > arr[j + 1])

                flag1 = 0;

        }

    }

    for (i = 0; i < a; i++)

    {
        for (j = 0; j < a - i - 1; j++)

        {

            if (arr[j] < arr[j + 1])

                flag2 = 0;

        }

    }

    if (0 == flag1 && 0 == flag2)

        printf("unsorted");

    else

        printf("sorted");

}
//˼·�����Բ��ŵ�˼·�߱�������ж�
void  is_sorted2(void) 
{

    int a;
    int flag1 = 0;//����
    int flag2 = 0;//����
    int i = 0;
    int arr[51] = { 0 };
    scanf("%d", &a);
    for (i = 0; i < a; i++)

    {

        scanf("%d ", &arr[i]);

        if (i > 0)
        {
            if (arr[i] > arr[i - 1])
                flag1 = 1;
            else
                flag2 = 1;
        }

    }

    if (1 == flag1 && 1 == flag2)

        printf("unsorted");

    else

        printf("sorted");

    return 0;

}