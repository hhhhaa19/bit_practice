#define _CRT_SECURE_NO_WARNINGS 1
//练习使用库函数，qsort排序各种类型的数据
//！！！void qsort (void* base, size_t num, size_t size,int (*compar)(const void*, const void*))
//qsort 函数内进行对int (*compar)(const void*, const void*)值进行处理
//整型
int cpar_int (const void* p1, const void* p2 ) 
{
	return *((int*)p2) - *((int*)p1);
}
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cpar_int);
//	//cpar_int 相当于add; qsort相当于cum,这里我们不知道qsort内部操作
//	return 0;
//}
//结构体
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

//模仿qsort的功能实现一个通用的冒泡排序
//交换
//void swap(char* p1, char* p2, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		char temp = *p1;//temp的类型要是char,以字节为单位处理
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
//			if (compar((char*)base + size * j, (char*)base +  size *( j+1))>0)//比较，可能有不同类型,封装时使用范围更大
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