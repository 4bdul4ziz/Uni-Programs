// implement djikstra's shortest path algorithm
//
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <chrono>

void djikstra()
{
    // read in graph
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, INT_MAX));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    // read in start and end
    int start, end;
    std::cin >> start >> end;

    // initialize distance
    std::vector<int> distance(n, INT_MAX);
    distance[start] = 0;
    std::vector<bool> visited(n, false);
}


int main()
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    int graph[][3] = {{0, 1, 2}, {0, 2, 3}, {0, 3, 4}, {1, 2, 5}, {1, 3, 6}, {1, 4, 7}, {2, 4, 8}, {3, 4, 9}, {3, 5, 10}, {4, 5, 11}, {4, 6, 12}};
    djikstra(graph, 9);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    int x = 10;
    int y = duration.count();
    FILE *fp = NULL;
    FILE *gnupipe = NULL;
    char *GnuCommands[] = {"set title \"Abdul Aziz A.B - 20BRS1185 - Shortest Path Graph\"", "plot 'data.tmp'"};

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

    std::cout << "Time taken by function: "
              << duration.count() << " microseconds" << std::endl;
    return 0;
}
