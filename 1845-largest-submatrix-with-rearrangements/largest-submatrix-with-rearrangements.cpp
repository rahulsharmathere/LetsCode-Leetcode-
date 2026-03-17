class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>> height = matrix;

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(height[i][j])
                    height[i][j] += height[i-1][j];
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){
            vector<int> row = height[i];

            sort(row.begin(), row.end(), greater<int>());

            for(int j=0;j<m;j++){
                ans = max(ans, row[j] * (j+1));
            }
        }

        return ans;

    }
};