class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        //dijkstra-min effort
        //up down left right
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
        //effort by now , {i,j}

        vector<vector<int>>efforts(n,vector<int>(m,INT_MAX));
        efforts[0][0]=0;
        pq.push({0,{0,0}});
        
        vector<int>drow={0,0,1,-1};
        vector<int>dcol={1,-1,0,0};

        while(!pq.empty()){
            int wt=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            // if(efforts[r][c]<wt)continue;
            if (r == n-1 && c == m-1) return wt; 

            for(int k=0;k<4;k++){
                int nr=r+drow[k];
                int nc=c+dcol[k];
                if(nr<n && nc<m && nr>=0 && nc>=0){
                    int newEff = max(wt, abs(heights[nr][nc] - heights[r][c]));
                    if (newEff < efforts[nr][nc]) {
                        efforts[nr][nc] = newEff;
                        pq.push({newEff, {nr, nc}});
                    }
                }
            }
        }
        return efforts[n-1][n-1];
    }
};