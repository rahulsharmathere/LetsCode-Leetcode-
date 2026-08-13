class Solution {
public:
    bool solve(vector<vector<int>>& mark, int k) {
    int minRow = INT_MAX;
    int maxRow = INT_MIN;
    int minCol = INT_MAX;
    int maxCol = INT_MIN;

    bool found = false;

    for (int i = 0; i < mark.size(); i++) {
        for (int j = 0; j < mark[0].size(); j++) {
            if (mark[i][j] >= k) {
                found = true;

                minRow = min(minRow, i);
                maxRow = max(maxRow, i);

                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }
        }
    }

    if (!found)
        return false;

    if (maxRow - minRow >= k)
        return true;

    if (maxCol - minCol >= k)
        return true;

    return false;
}
    
    int maxArea(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>mark(n+1,vector<int>(m+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]==1){
                    mark[i][j]=min(mark[i+1][j],min(mark[i][j+1],mark[i+1][j+1]))+1;
                }
            }
        }
        int s=1;
        int e=min(n,m);
        int ans=0;



        while(s<=e){
            int mid=s+(e-s)/2;
            if(solve(mark,mid)==1){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans*ans;
    }
};