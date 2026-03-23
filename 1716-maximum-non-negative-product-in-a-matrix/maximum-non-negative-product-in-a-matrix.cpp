class Solution {
public:
    //do again good question 
    //DP on grids (negatives make it goat)
    int n, m;
    const int MOD = 1e9 + 7;
    
    vector<vector<long long>> dpMax, dpMin;
    
    void solve(vector<vector<int>>& grid, int i, int j){
        if(i >= n || j >= m) return;
        if(dpMax[i][j] != LLONG_MIN) return;
        if(i == n-1 && j == m-1){
            dpMax[i][j] = dpMin[i][j] = grid[i][j];
            return;
        }
        solve(grid, i+1, j);
        solve(grid, i, j+1);
        long long val = grid[i][j];
        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;
        if(i+1 < n){
            maxi = max(maxi, max(val * dpMax[i+1][j], val * dpMin[i+1][j]));
            mini = min(mini, min(val * dpMax[i+1][j], val * dpMin[i+1][j]));
        }
        if(j+1 < m){
            maxi = max(maxi, max(val * dpMax[i][j+1], val * dpMin[i][j+1]));
            mini = min(mini, min(val * dpMax[i][j+1], val * dpMin[i][j+1]));
        }
        
        dpMax[i][j] = maxi;
        dpMin[i][j] = mini;
    }
    
    int maxProductPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        dpMax.assign(n, vector<long long>(m, LLONG_MIN));
        dpMin.assign(n, vector<long long>(m, LLONG_MAX));
        
        solve(grid, 0, 0);
        
        long long ans = dpMax[0][0];
        
        if(ans < 0) return -1;
        
        return ans % MOD;
    }
};