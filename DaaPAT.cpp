// Design a solution that can solve the problem given below:

/* Let 'A' be an array with 'n' positive integers and 'n' be even. Array A is constructed in such a way that, alternate numbers are always odd and even. This means, no two odd or even numbers can be neighbors. For instance, A = 1 2 3 4 5 6.

You are expected to develop a solution, that gets input for the array thereby validating the property provided above, and to create a new array with values where the odd numbers should appear first in the descending order and then even numbers in ascending order. When validating the Input, if it violates the property, you are must print -1, else print the desired output.

Sample Input 1:

1 2 3 4 5 6

Output

5 3 1 2 4 6



Sample Input 2:

1 2 3 4 5

Output

-1

Sample Input 3:

2 4 5 6

Output

-1 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function to print array in descending order with odd numbers first and then even numbers in ascending order
void printArray(vector<int> &arr)
{
    int n = arr.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        while (i < j && arr[i] % 2 == 1)
        {
            i++;
        }
        while (i < j && arr[j] % 2 == 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void Check(vector<int> &A)
{
    int n = A.size();
    int i = 0;
    while (i < n)
    {
        if (A[i] % 2 == 0)
        {
            if (i == n - 1)
            {
                cout << -1;
                return;
            }
            if (A[i + 1] % 2 == 0)
            {
                cout << -1;
                return;
            }

            i += 2;
        }
        if (A[i] % 2 == 1)
        {
            if (i == n - 1)
            {
                cout << -1;
                return;
            }
            if (A[i + 1] % 2 == 1)
            {
                cout << -1;
                return;
            }

            i += 2;
        }
        else
        {
            printArray(A);
        }
    }

    sort(A.begin(), A.end());
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

// function to check that no two odd or even numbers are neighbors
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    Check(A);
    return 0;
}
