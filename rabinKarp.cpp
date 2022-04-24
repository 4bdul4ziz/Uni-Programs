/* Write a program to identify the occurrence of pattern P in the original text T using Rabin - Karp method

    Sample Input :

    Raman_is_going_to_party

    party

    Output :

    Pattern occurs with shift 19 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

// function to find string matching shifts with rabin karp method

void find_shift_rabin_karp(const std::string T, const std::string P)
{
    int n = T.length();
    int m = P.length();
    int p = 31;
    int q = 1;
    int d = 1;
    for (int i = 1; i < m; i++)
        d = (d * p) % q;
    int h = 0;
    for (int i = 0; i < m; i++)
        h = (h * p + P[i]) % q;
    int h1 = 0;
    for (int i = 0; i < m; i++)
        h1 = (h1 * p + T[i]) % q;
    for (int i = 0; i <= n - m; i++)
    {
        if (h == h1)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (T[i + j] != P[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                std::cout << "Pattern occurs with shift " << i << std::endl;
        }
        if (i < n - m)
            h1 = (h1 * p + T[i + m] - d * T[i]) % q;
    }
}

int main()
{
    std::string T, P;
    std::cout << "Enter the original text: ";
    std::cin >> T;
    std::cout << "Enter the pattern: ";
    std::cin >> P;
    find_shift_rabin_karp(T, P);
    return 0;
}
