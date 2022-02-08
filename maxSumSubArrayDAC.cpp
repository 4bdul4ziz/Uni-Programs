#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
//q2 maximum sub array using divide and conquer
/* int maxSubArray(vector<int>& nums, int low, int high)
{   gae 
    if (low == high)
        return nums[low];
    int mid = (low + high) / 2;
    int left_sum = maxSubArray(nums, low, mid);
    int right_sum = maxSubArray(nums, mid + 1, high);
    int cross_sum = maxCrossingSum(nums, low, mid, high);
    return max(max(left_sum, right_sum), cross_sum);
} */

int maxSubArray(vector<int> &nums, int low, int high)
{
    if (low == high)
        return nums[low];
    int mid = (low + high) / 2;
    int left_sum = maxSubArray(nums, low, mid);
    int right_sum = maxSubArray(nums, mid + 1, high);
    int cross_sum = 0;
    int left_max = nums[mid];
    int right_max = nums[mid + 1];
    for (int i = mid; i >= low; i--)
    {
        left_max = max(left_max, nums[i]);
        cross_sum += left_max;
    }
    for (int i = mid + 1; i <= high; i++)
    {
        right_max = max(right_max, nums[i]);
        cross_sum += right_max;
    }
    return max(max(left_sum, right_sum), cross_sum);
}
int maxSubArrayDAC(vector<int> &nums)
{
    return maxSubArray(nums, 0, nums.size() - 1);
}
//function for max crossing sum
int maxCrossingSum(vector<int> &nums, int low, int mid, int high)
{
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += nums[i];
        left_sum = max(left_sum, sum);
    }
    int right_sum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += nums[i];
        right_sum = max(right_sum, sum);
    }
    return left_sum + right_sum;
}

//function to print indexes of elements
void printIndexes(vector<int> &nums, int low, int high)
{
    if (low == high)
    {
        cout << low << " ";
        return;
    }
    int mid = (low + high) / 2;
    printIndexes(nums, low, mid);
    printIndexes(nums, mid + 1, high);
}

int main()
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int max_sum = maxSubArrayDAC(nums);
    cout << max_sum << endl;
    printIndexes(nums, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}

/* int main()
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(8);
    nums.push_back(6);
    nums.push_back(12);
    nums.push_back(11);
    nums.push_back(9);
    nums.push_back(14);
    nums.push_back(3);
    cout << maxSubArrayDAC(nums) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
} */
