class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<int, greater<int>>pq; //priority queue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pq.insert(grid[i][j]);
                for(int k=1; ;k++){
                    if(i-k<0 || i+k>=n || j-k<0 || j+k>=m)break;
                    int sum=0;
                    
                    for(int t=0;t<k;t++){
                        sum+=grid[i-k+t][j+t];
                    }
                    for(int t=0;t<k;t++){
                        sum+=grid[i+t][j+k-t];
                    }
                    for(int t=0;t<k;t++){
                        sum+=grid[i+k-t][j-t];
                    }
                    for(int t=0;t<k;t++){
                        sum+=grid[i-t][j-k+t];
                    }

                    pq.insert(sum);
                }
            }
        }
        vector<int> ans;

        for(auto x:pq){
            ans.push_back(x);
            if(ans.size()==3) break;
        }

        return ans;
    }
};