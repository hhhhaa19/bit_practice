#define _CRT_SECURE_NO_WARNINGS 1

void P_struct(void)
{
	typedef struct stu
	{
		char name[20];
		int age;
		long long phone;
		float score;
	}stu;
	stu zhansan= { "张三",20,18812345678,2.678 };
	stu* pa = &zhansan;
	printf("%s %d %lld %.3f\n", zhansan.name, zhansan.age, zhansan.phone, zhansan.score);
	//用指针来操作
	printf("%s %d %lld %.3f\n", pa->name, pa->age, pa->phone, pa->score);

	
}

