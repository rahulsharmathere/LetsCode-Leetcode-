class Solution {
public:
    int m, n;

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;

        int gold = grid[i][j];
        grid[i][j] = 0;   // mark visited

        int up    = dfs(grid, i - 1, j);
        int down  = dfs(grid, i + 1, j);
        int left  = dfs(grid, i, j - 1);
        int right = dfs(grid, i, j + 1);

        grid[i][j] = gold;  

        return gold + max({up, down, left, right});
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0)
                    ans = max(ans, dfs(grid, i, j));
            }
        }

        return ans;
    }
};