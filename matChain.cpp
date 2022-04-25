#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> rc;

int B(int i, int j)
{
    if (i == j)
        return 0;

    int mink = INT_MAX;
    for (int k = i; k < j; k++)
    {
        mink = min(mink, B(i, k) + B(k + 1, j) + rc[i] * rc[k + 1] * rc[j + 1]);
    }

    return mink;
}

int main()
{
    int c;
    cin >> c;
    rc = vector<int>(c + 1, -1);
    int x;

    // for every matrix i, rc[i] is row and rc[i+1] is column.
    for (int i = 1; i <= c; i++)
    {
        cin >> x;
        rc[i] = x;
    }

    int n = c - 1;
    cout << B(1, n);
}

/*
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> rc;
vector< vector<int> > DP;

int main()
{
    int c; cin >> c;
    int n = c - 1;
    rc = vector<int>(c+1, -1);
    DP = vector< vector<int> >(c, vector<int>(c, 0));
    int x;

    // for every matrix i, rc[i] is row and rc[i+1] is column
    for (int i = 1; i <= c; i++) {
        cin >> x;
        rc[i] = x;
    }

    for (int w = n; w > 0; w--) {
        int p = n - w;
        for (int j = n; j > p; j--) {
            int i = j - p - 1;
            DP[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k + 1][j]
                    + rc[i] * rc[k + 1] * rc[j + 1]);
            }
        }
    }

    cout << DP[1][n];
}
*/