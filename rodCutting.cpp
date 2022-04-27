#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

int rodCutting(int n, std::vector<int> &p, std::vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int max_profit = -1;
    for (int i = 1; i <= n; i++)
    {
        max_profit = std::max(max_profit, p[i] + rodCutting(n - i, p, dp));
        // return max_profit;
    }
    dp[n] = max_profit;
    return max_profit;
    return dp[n];
}

int main()
{
    using namespace std::chrono;
    std::vector<int> p = {1, 5, 8, 9, 10, 17, 17, 20}; // profits
    std::vector<int> dp(p.size(), -1);                 // no. of the cuts
    for (int i = 0; i < p.size(); i++)
    {
        printf("%d ", dp[i]);
    }
    int n = p.size() - 1; // size of the rod
    auto start = std::chrono::high_resolution_clock::now();
    int q = rodCutting(n, p, dp);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Rod Cutting: " << q << " in " << duration.count() << " microseconds" << std::endl;
    int x = 100;
    int y = duration.count();
    FILE *fp = NULL;
    FILE *gnupipe = NULL;
    char *GnuCommands[] = {"set title \"Abdul Aziz A.B - 20BRS1185 - Rod Cutting Performance Graph\"", "plot 'data.tmp'"};

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