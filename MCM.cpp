#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printOperations(const vector<vector<int>> &ops)
{
    cout << "Cost of the operations:" << endl;

    for (auto vec : ops)
    {
        for (auto elem : vec)
        {
            cout << elem << " ";
        }
        cout << endl;
    }

    cout << endl;
}

int computeMinimumNumberOfMultiplicationOperations(const vector<pair<int, int>> &matrices)
{
    vector<vector<int>> operations(matrices.size(), vector<int>(matrices.size()));

    for (int len = 2; len <= matrices.size(); len++)
    {
        for (int i = 0; i <= matrices.size() - len; i++)
        {
            int j = i + len - 1;

            int cost = INT_MAX;

            for (int k = i; k < j; k++)
            {
                cost = min(cost, operations.at(i).at(k) + operations.at(k + 1).at(j) + matrices.at(i).first * matrices.at(k).second * matrices.at(j).second);
            }

            operations.at(i).at(j) = cost;
        }
    }

    printOperations(operations);

    return *operations.at(0).rbegin();
}

int main()
{
    vector<pair<int, int>> matrices = {
        {2, 3},
        {3, 6},
        {6, 4},
        {4, 5}};

    int cost = computeMinimumNumberOfMultiplicationOperations(matrices);

    cout << "Minimum operation cost = " << cost << endl;

    return 0;
}