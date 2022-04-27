/*
Given a two dimensional array say nxm, write an algorithm to find the total number of paths that are possible to travel from the top-left cell to bottom right cell.
You are allowed to move only right or downwards. For Ex: if nxm is 2x2, then the number of possible path is only two as shown in figure below.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    int dp[n][m];
    dp[0][0] = mat[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + mat[i][0];
    }
    for (int i = 1; i < m; i++)
    {
        dp[0][i] = dp[0][i - 1] + mat[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + mat[i][j];
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
