#include <stdio.h>
#include <stdlib.h>
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
}

void selection_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];

                arr[j] = temp;
            }
        }
    }
    printf("After Selection sort Elements are : ");
    display(arr, n);
}
void insertion_sort(int arr[], int n)
{
    int i, j, min;
    for (i = 1; i < n; i++)
    {
        min = arr[i];
        j = i - 1;
        while (min < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = min;
    }
    printf("After Insertion sort Elements are : ");
    display(arr, n);
}
int main()
{
    int n, choice, i;
    char ch[20];
    printf("Number Of Elements: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter %d Element : ", i + 1);
        scanf("%d", &arr[i]);
    }
    while (1)
    {
        printf("\nMenu: \n");
        printf("\n1. Selection Sort\n2. Insertion Sort\n3. Display Array.\n4. Exit the Program.\n");
        printf("\nEnter your Choice : ");
        scanf("%d", &choice);
        switch (choice)

        {
        case 1:
            selection_sort(arr, n);
            break;
        case 2:
            insertion_sort(arr, n);
            break;
        case 3:
            display(arr, n);
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
    return 0;
}