/*
Consider a sequence of ‘n’ matrices <M1,M2,..,Mn>, where the matrix Mi is of dimension di-1di. The sequence of ‘n’ matrices <M1,M2,..,Mn> must
have “n+1”  dimensions. Design and implement an algorithm that minimizes the number of multiplications required to perform matrix chain
multiplication between the sequence of ‘n’ matrices with n+1 dimensions and print the optimal parenthesization for the sequence of dimensions
and multiplication.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rc;
vector<int> DP;

int B(int i, int j)
{
    if (i == j)
        return 0;

    int mink = INT_MAX;
    for (int k = i; k < j; k++)
    {
        mink = min(mink, B(i, k) + B(k + 1, j) + rc[i] * rc[k + 1] * rc[j + 1]);
    }

    return mink;
}

int distance(int i, int j)
{
    return rc[i] * rc[j + 1];
}

int cost()
{
    int n = rc.size() - 1;
    DP = vector<vector<int>>(n, vector<int>(n, 0));
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            DP[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k + 1][j] + distance(i, k) * distance(k + 1, j));
            }
        }
    }
    return DP[1][n];
}

void parenthesization(int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
        return;
    }

    int mink = INT_MAX;
    int k;
    for (k = i; k < j; k++)
    {
        mink = min(mink, B(i, k) + B(k + 1, j) + rc[i] * rc[k + 1] * rc[j + 1]);
    }

    if (mink == DP[i][j])
    {
        cout << "(";
        parenthesization(i, k);
        parenthesization(k + 1, j);
        cout << ")";
    }
    else
    {
        cout << "A" << i;
        parenthesization(i + 1, j);
    }
}

int main()
{
    int c;
    cin >> c;
    rc = vector<int>(c + 1, -1);
    int x;

    // for every matrix i, rc[i] is row and rc[i+1] is column.
    for (int i = 1; i <= c; i++)
    {
        cin >> x;
        rc[i] = x;
    }

    cout << B(1, c - 1) << endl;
    cout << cost() << endl;
    parenthesization(1, c - 1);
    cout << endl;
}