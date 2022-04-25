/*
Given an array, find the total number of reversal pairs of it. If (i < j) and (A[i] > A[j]), then pair (i, j) is called a reversal pair of an array A. We need to count all such pairs in the array.

Input:  A[] = [1, 9, 6, 4, 5]

Output: The number of reversal pairs is 5

There are 5 reversal pairs in the array: (9, 6), (9, 4), (9, 5), (6, 4), (6, 5)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

void reversalPairs(vector<int> &A)
{
    int n = A.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                count++;
            }
        }
    }
    cout << count << endl;
}

int main()
{
    // take length of vector
    int n;
    cin >> n;
    vector<int> A(n);
    // take elements of vector
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    reversalPairs(A);
}

// g++ -std=c++11 <filename>