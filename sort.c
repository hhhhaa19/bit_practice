#define _CRT_SECURE_NO_WARNINGS 1
//��ϰʹ�ÿ⺯����qsort����������͵�����
//������void qsort (void* base, size_t num, size_t size,int (*compar)(const void*, const void*))
//qsort �����ڽ��ж�int (*compar)(const void*, const void*)ֵ���д���
//����
int cpar_int (const void* p1, const void* p2 ) 
{
	return *((int*)p2) - *((int*)p1);
}
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cpar_int);
//	//cpar_int �൱��add; qsort�൱��cum,�������ǲ�֪��qsort�ڲ�����
//	return 0;
//}
//�ṹ��
struct stu {
	char name[10];
	int age;
};
int cmp_stu_age(void* p1, void* p2)
{
	return ((struct stu*)p2)->age - ((struct stu*)p1)->age;
}
int cmp_stu_name(void* p1, void* p2)
{
	return strcmp(((struct stu*)p2)->name, ((struct stu*)p1)->name);
 }
int main()
{
	struct stu stus[2] = { {"hh",10},{"aa",20} };
	qsort(&stus,sizeof(stus)/sizeof(stus[1]),sizeof(stus[1]),cmp_stu_name);
}

//ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������
//����
//void swap(char* p1, char* p2, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		char temp = *p1;//temp������Ҫ��char,���ֽ�Ϊ��λ����
//		*p1 = *p2;
//		*p2 = temp;
//		p1++;
//		p2++;
//	}
//}
//
//void Bsort(void* base, int num, int size, int (*compar)(const void*, const void*))
//{
//	int i, j;
//	for(i=0;i<num-1;i++)
//	{
//		for (j = 0; j < num - i - 1; j++)
//		{
//			if (compar((char*)base + size * j, (char*)base +  size *( j+1))>0)//�Ƚϣ������в�ͬ����,��װʱʹ�÷�Χ����
//			{
//				swap((char*)base + size * j, (char*)base + size * (j + 1),size);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,3,4,5,2,10,9,8,6,7 };
//	Bsort(arr, sizeof(arr) / sizeof(arr[1]), sizeof(arr[1]), cpar_int);
//	//
//	return 0;
//}