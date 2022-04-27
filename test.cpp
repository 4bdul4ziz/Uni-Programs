#include <iostream>
//#include <chrono>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
// using namespace std::chrono;

int missing_num_in_series(int arr[], int n) // using binary search to find the missing number
{
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == mid)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int missing = missing_num_in_series(arr, n);
    cout << "The missing number is " << missing;
    return 0;
}
/*     int arr1[] = {1, 3, 5, 7, 11};
    int arr2[] = {1, 4, 7, 13, 16};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int missing = missing_num_in_series(arr1, n1);
    cout << "The missing term from the AP sequence is : " << endl;
    cout << missing << endl;
    missing = missing_num_in_series(arr2, n2);
    cout << "The missing term from the AP sequence is : " << endl;
    cout << missing << endl;
    return 0; */
