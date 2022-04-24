/*
You are given a 3x3 grid to fill the nine positions in the grid using integers from 1 to 9 where no number should be repeated in the grid. Design an algorithm to fill the nine positions in the grid, such that, sum of the elements of any two rows should be equal.

Input: 3

Output:

1 6 7

4 2 8

5 9 3

* The Output is a sample test case created. This program has many outputs and you are requested to closely match the test case provided to complete this IPS
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

int main()
{
    int grid[3][3];
    int sum = 0;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sum -= grid[i][j];
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (sum % 2 == 0)
            {
                printf("%d ", grid[i][j]);
            }
            else
            {
                printf("%d ", grid[i][j] + 1);
            }
        }
        printf("\n");
    }
    return 0;
}