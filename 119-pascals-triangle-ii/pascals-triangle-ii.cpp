class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>>DP(n+1);

        for(int i=0;i<=n;i++)DP[i]=vector<int>(i+1,1);

        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                DP[i][j]=DP[i-1][j-1]+DP[i-1][j];
            }
        }
        return DP[n];
    }
};