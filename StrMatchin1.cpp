/* Write a program to identify the occurrence of pattern P in the original text T.
User should be able to enter two strings when prompted.
Your Program should take the first string as T and the second string as P to check.

Sample Input:

Raman_is_going_to_party

party

Output:

Pattern occurs with shift 19 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
void PatternCheck(std::string)
{
    std::string T, P;
    std::cout << "Enter the original text: ";
    std::cin >> T;
    std::cout << "Enter the pattern: ";
    std::cin >> P;
    int n = T.length();
    int m = P.length();
    int lcs[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                lcs[i][j] = 0;
            else if (T[i - 1] == P[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    int shift = 0;
    for (int i = 0; i <= n; i++)
    {
        if (lcs[i][m] == m)
        {
            shift = i - m;
            std::cout << "Pattern occurs with shift " << shift << std::endl;
            break;
        }
        else if (i == n)
            std::cout << "Pattern does not occur" << std::endl;
    }
    // std::cout << "Pattern occurs with shift " << shift << std::endl;
}

int main()
{
    PatternCheck("Raman_is_going_to_party");
    return 0;
}
// function to find all occuring indices of the pattern in the given string

// Monday_is_a_sunnyday_and_its_a_Holiday, day