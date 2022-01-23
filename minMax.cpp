#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;
void insertionSort(int arr[], int length);
void printArray(int array[], int size);

int main()
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    int p = 10;
    int i, j;
    int arr[10] = {89, 79, 97, 69, 56, 89, 99, 100, 78, 67};
    insertionSort(arr, p);

    cout << "\n Max Marks = " << *max_element(arr, arr + p) << endl;
    cout << "\n Min Marks = " << *min_element(arr, arr + p) << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    int x = 10;
    int y = duration.count();
    FILE *fp = NULL;
    FILE *gnupipe = NULL;
    char *GnuCommands[] = {"set title \"Abdul Aziz A.B - 20BRS1185 - Insertion Sort Graph\"", "plot 'data.tmp'"};

    fp = fopen("data.tmp", "w");
    gnupipe = popen("gnuplot -persitent", "w");

    for (int i = 0; i < x; i++)
    {
        fprintf(fp, "%d %d\n", x, y);

        x = x - 1;
        y = y - 1;
    }

    for (int i = 0; i < 2; i++)
    {
        fprintf(gnupipe, "%s\n", GnuCommands[i]);
    }

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

void insertionSort(int arr[], int length)
{
    int i, j, tmp;
    for (i = 1; i < length; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
        printArray(arr, 10);
    }
}
void printArray(int array[], int size)
{
    cout << "Sorting the array using insertion";
    int j;
    for (j = 0; j < size; j++)
        for (j = 0; j < size; j++)
            cout << " " << array[j];
    cout << endl;
}