#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//maximum subarray sum
int maxSubArraySum(vector<int> arr, int size)
{
    int max_so_far = 0, max_ending_here = 0;
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}
//main function
int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    vector<int> arr(size);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Maximum contiguous sum is " << maxSubArraySum(arr, size);
    return 0;
}
