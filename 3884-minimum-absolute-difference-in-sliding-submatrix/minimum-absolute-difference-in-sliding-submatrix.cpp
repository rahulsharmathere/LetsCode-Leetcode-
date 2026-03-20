class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n-k+1,vector<int>(m-k+1,0));
        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                vector<int>inner;
                for(int p=i;p<i+k;p++){
                    for(int q=j;q<j+k;q++){
                        inner.push_back(grid[p][q]);
                    }
                }
                sort(inner.begin(),inner.end());
                int mini = INT_MAX;
                for(int z = 0; z < inner.size() - 1; z++){
                    if(inner[z] != inner[z+1]) {
                        mini = min(mini, inner[z+1] - inner[z]);
                    }
                }
                if(mini == INT_MAX) mini = 0;
                ans[i][j]=mini;

            }
        }
        return ans;
    }
};