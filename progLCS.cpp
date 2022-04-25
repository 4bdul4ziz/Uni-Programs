// LCS program

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

// graphical matrix for visuallising LCS program
// basic lcs with dynamic programming
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

// sequence of the lcs with recurive method
std::string lcs_recur(std::string str1, std::string str2)
{
    int n = str1.length() - 1;
    int m = str2.length() - 1;
    if (n == 0 || m == 0)
        return "";
    else if (str1[n - 1] == str2[m - 1])
        return lcs_recur(str1.substr(0, n - 1), str2.substr(0, m - 1)) + str1[n - 1];
    else
    {
        if (lcs_recur(str1.substr(0, n - 1), str2) > lcs_recur(str1, str2.substr(0, m - 1)))
            return lcs_recur(str1.substr(0, n - 1), str2);
        else
            return lcs_recur(str1, str2.substr(0, m - 1));
    }
}

int main()
{
    using namespace std::chrono;
    auto start = std::chrono::high_resolution_clock::now();
    std::string str1 = "ABCBDAB";
    std::string str2 = "BCDABA";
    std::cout << "Length of LCS is " << lcs(str1, str2) << std::endl;
    std::cout << "LCS sequence is " << lcs_recur(str1, str2) << std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "LCS program: " << duration.count() << " microseconds" << std::endl;
    int x = 100;
    int y = duration.count();
    FILE *fp = NULL;
    FILE *gnupipe = NULL;
    char *GnuCommands[] = {"set title \"Abdul Aziz A.B - 20BRS1185 - LCS Performance Graph\"", "plot 'data.tmp'"};

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
    return 0;
}