#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define size 10000

int a[size];

swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
main()
{
    int n, index, min;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        min = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                index = j;
            }
        }
        swap(&a[i], &a[index]);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}