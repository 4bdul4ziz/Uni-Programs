/*
A grocery shop 'ABC' has got 'n' type of items in packages of same size and different prices. Rita goes for a shopping to shop 'ABC' with 'k' empty bags. She shall buy only 'k' different items and she will put only same type of items in a bag. Given the prices of 'n' items in 'ABC' and capacity of 'k' bags in hand, develop an algorithm to find the money to taken by rita for shopping so that she can 'k' buy different items as she wish. Assume that the shop has got stock of all the items as much as required by Rita

For example, if there are 10 items in the shop with the prices 20, 17, 5, 18, 25, 11, 9, 22, 31, 7 and rita has got four bags of capacity as 4, 10, 7, 8 then the money to be taken for shopping is 744

Input Format

First line contains the number of items in the shop, n

Next line contains the cost of 'n' items in the shop, separated by a space

Next line contains the number of bags with rita, k

Next line contains capacity of 'k' bags, separated by a space

Output Format

print the money to be taken in hand
*/

/* sample input
10
20 17 5 18 25 11 9 22 31 7
4
4 10 7 8


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> prices(n);
    for (int i = 0; i < n; i++)
        std::cin >> prices[i];
    std::vector<int> capacity(k);
    for (int i = 0; i < k; i++)
        std::cin >> capacity[i];
    std::sort(prices.begin(), prices.end());
    std::sort(capacity.begin(), capacity.end());
    int money = 0;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < k && prices[i] > capacity[j])
            j++;
        if (j < k)
            money += prices[i];
    }
    std::cout << money;
    return 0;
}