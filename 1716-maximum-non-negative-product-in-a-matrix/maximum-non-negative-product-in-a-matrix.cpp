class Solution {
public:

    void solve(vector<vector<int>>& grid, int i, int j, vector<vector<long long>>& dpMax, vector<vector<long long>>& dpMin,int n, int m) {

        if (i >= n || j >= m) return;

        // already computed
        if (dpMax[i][j] != LLONG_MIN) return;
        if (i == n - 1 && j == m - 1) {
            dpMax[i][j] = dpMin[i][j] = grid[i][j];
            return;
        }
        solve(grid, i + 1, j, dpMax, dpMin, n, m);
        solve(grid, i, j + 1, dpMax, dpMin, n, m);

        long long val = grid[i][j];

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;
        if (i + 1 < n) {
            long long a = val * dpMax[i + 1][j];
            long long b = val * dpMin[i + 1][j];
            maxi = max(maxi, max(a, b));
            mini = min(mini, min(a, b));
        }
        if (j + 1 < m) {
            long long a = val * dpMax[i][j + 1];
            long long b = val * dpMin[i][j + 1];
            maxi = max(maxi, max(a, b));
            mini = min(mini, min(a, b));
        }

        dpMax[i][j] = maxi;
        dpMin[i][j] = mini;
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dpMax(n, vector<long long>(m, LLONG_MIN));
        vector<vector<long long>> dpMin(n, vector<long long>(m, LLONG_MAX));

        solve(grid, 0, 0, dpMax, dpMin, n, m);

        long long ans = dpMax[0][0];

        if (ans < 0) return -1;

        return ans % MOD;
    }
};