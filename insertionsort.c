#include <stdio.h>
#include <stdlib.h>

typedef u_int8_t byte;

void swap_int(int *a, int *b);
void getArrElemVals(int **arrPtr, int len);
void allocateArray_int(int **arrPtr, byte arrLen);
void insertionSort(int *arrPtr1, int **arrPtr2, byte arrLen);
void printArrElems(int *arr, byte arrLen);

int main()
{

    auto int *arr1;
    auto int *arr2;
    auto byte arrLen;

    printf("Please enter a length for array: ");
    scanf("%i", &arrLen);

    if (arrLen > 255)
        return 0;

    allocateArray_int(&arr1, arrLen);
    allocateArray_int(&arr2, arrLen);

    getArrElemVals(&arr1, arrLen);

    insertionSort(arr1, &arr2, arrLen);

    printArrElems(arr2, arrLen);

    free(arr1);
    free(arr2);
    return 0;
}

void swap_int(int *a, int *b)
{

    auto int tmp = *a;
    *a = *b;
    *b = tmp;
}

void allocateArray_int(int **arrPtr, byte arrLen)
{

    *arrPtr = calloc((size_t)arrLen, sizeof(int));

    if (*arrPtr == NULL)
    {
        printf("\nArray Allocation FAILED !!!\n");
        exit(0);
    }
}

void getArrElemVals(int **arrPtr, int len)
{

    for (register byte i = 0; i < len; i++)
    {

        printf("Value of Index %i: ", i);
        scanf("%i", (*arrPtr + i));
    }
}

void insertionSort(int *arrPtr1, int **arrPtr2, byte arrLen)
{

    *(*arrPtr2) = *arrPtr1;

    for (register byte i = 1; i < arrLen; i++)
    {

        *(*arrPtr2 + i) = *(arrPtr1 + i);

        register byte elemIndex = i;

        while (elemIndex != 0 && *(*arrPtr2 + elemIndex) < *(*arrPtr2 + (elemIndex - 1)))
        {

            swap_int(*arrPtr2 + elemIndex, *arrPtr2 + elemIndex - 1);
            elemIndex--;
        }
    }
}

void printArrElems(int *arr, byte arrLen)
{

    for (register byte i = 0; i < arrLen; i++)
        printf("%i, ", *(arr + i));

    printf("\b\b\n");
}