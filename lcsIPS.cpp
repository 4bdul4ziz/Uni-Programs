#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int lcs(std::string str1, std::string str2)
{
    int n = str1.length();
    int m = str2.length();
    int lcs[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                lcs[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    return lcs[n][m];
}

int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    std::cout << "Length of LCS is " << lcs(str1, str2) << std::endl;

    return 0;
}