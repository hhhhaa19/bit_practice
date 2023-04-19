#define _CRT_SECURE_NO_WARNINGS 1

void mock_log(void)
{
	int i;
	char ID [10] = {0};
	printf("input your user ID password:\n");
	for (i = 0; i < 3; i++)
	{
		scanf("%s", ID);
		if (strcmp(ID, "123456") == 0)
		{
			printf("pass\n");
			break;
		}
		else
		{
			Sleep(30120);
			system("cls");
		}
	}
	if (i == 3)
	{
		printf("no\n");
	}
}