#define _CRT_SECURE_NO_WARNINGS 1
void merge()
{
    int m, n;
    scanf("%d %d\n", &m, &n);
    int arr[1000];
    int arr2[1000];
    int tag[2000];
    int i = 0;
    int j = 0;
    for (i = 0; i < m; i++)
    {
        scanf("%d ", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d ", &arr2[i]);
    }
    i = 0;
    j = 0;
    while (i < m && j < n)
    {
        if (arr[i] < arr2[j])
        {
            tag[i + j] = arr[i];
            i++;
        }
        else
        {
            tag[i + j] = arr2[j];
            j++;
        }
    }
    if (i == m && j < n)
        for (int a = j; a < n; a++)
        {
            tag[i + a] = arr2[a];
        }
    else if (j == n && i < m)
    {
        for (int a = i; a < m; a++)
        {
            tag[j + a] = arr[a];
        }
    }
    for (i = 0; i < m + n; i++)
    {
        printf("%d ", tag[i]);
    }
}
