/*
Given a set of N items each having price P with Quantity Q and the total capacity C of a Container, Your task is to find the maximal value of fractions of items that can fit into the Container.

Sample Input:

50 // Capacity C

3 //N items

60, 20 //item 1

100, 50 //item 2

120, 30 //item 3

Sample Output:

180

Input
10
1
500 30
Expected output
166.67


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

// use float

int main()
{
    int n, c;
    cin >> c >> n;
    vector<int> v(n);
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> w[i];
    }
    int dp[n + 1][c + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][c] << endl;
}

/* int n, c;
cin >> n >> c;
vector<int> price(n);
vector<int> quantity(n);
for (int i = 0; i < n; i++)
{
    cin >> price[i] >> quantity[i];
}
vector<float> fraction(n);
for (int i = 0; i < n; i++)
{
    fraction[i] = (float)price[i] / (float)quantity[i];
}
sort(fraction.begin(), fraction.end());
float max = 0;
for (int i = 0; i < n; i++)
{
    if (fraction[i] * c > max)
    {
        max = fraction[i] * c;
    }
}
cout << max << endl; */