#include "LCS.hpp"
#include <vector>
#include <algorithm>

using namespace std;

string computeLCS(const string &x, const string &y) {
    int m = x.length();
    int n = y.length();
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));

    // Fill the LCS table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS from the table
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            lcs = x[i - 1] + lcs;
            --i;
            --j;
        } 
        else if (c[i - 1][j] > c[i][j - 1]) {
            --i;
        } 
        else {
            --j;
        }
    }

    return lcs;
}