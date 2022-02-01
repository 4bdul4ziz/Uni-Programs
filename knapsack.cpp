#include <iostream>
#include <vector>
#include <chrono>

using std::vector;

int get_max_index(vector<int> weights, vector<int> values)
{
    int max_i = 0;
    double max = 0;

    for (int i = 0; i < weights.size(); i++)
    {
        if (weights[i] != 0 && (double)values[i] / weights[i] > max)
        {
            max = (double)values[i] / weights[i];
            max_i = i;
        }
    }
    return max_i;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
    double value = 0.0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (capacity == 0)
            return value;
        int index = get_max_index(weights, values);
        int a = std::min(capacity, weights[index]);
        value += a * (double)values[index] / weights[index];
        weights[index] -= a;
        capacity -= a;
        printf("\nCurrent Iteration is: %d\n", i);
    }
    return value;
}

int main()
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    int capacity = 10;

    /*     printf("Enter the capacity of the knapsack: ");
    std::cin >> n >> capacity; */

    vector<int> values;
    values.push_back(5);
    values.push_back(3);
    values.push_back(4);
    values.push_back(8);
    values.push_back(6);
    values.push_back(12);
    values.push_back(11);
    values.push_back(9);
    values.push_back(14);
    values.push_back(3);

    vector<int> weights;
    weights.push_back(8);
    weights.push_back(5);
    weights.push_back(2);
    weights.push_back(4);
    weights.push_back(6);
    weights.push_back(7);
    weights.push_back(9);
    weights.push_back(10);
    weights.push_back(11);
    weights.push_back(3);

    /*    printf("Enter the value & weight of the knapsack: ");
    for (int i = 0; i < n; i++)
    {
        std::cin >> values[i] >> weights[i];
    } */
    double optimal_value = get_optimal_value(capacity, weights, values);
    std::cout.precision(10);
    std::cout << "\n"
              << "The optimal value is " << optimal_value << std::endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    int x = 10;
    int y = duration.count();
    FILE *fp = NULL;
    FILE *gnupipe = NULL;
    char *GnuCommands[] = {"set title \"Abdul Aziz A.B - 20BRS1185 - Knapsack Problem Graph\"", "plot 'data.tmp'"};

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

    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    return 0;
}