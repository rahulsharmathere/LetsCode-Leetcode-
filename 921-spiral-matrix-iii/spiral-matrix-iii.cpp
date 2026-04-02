class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int r, int c, int rStart, int cStart) {
        vector<vector<int>> ans;
        int total=r*c;

        int x=rStart;
        int y=cStart;
        ans.push_back({x, y});
        int len=1;
        vector<int>dx={0,1,0,-1}; 
        vector<int>dy={1,0,-1,0};
        int dir=0;
        while(ans.size()<total) {
            for(int k=0;k<2;k++) { 
                for(int i=0;i<len;i++) {
                    x+=dx[dir];
                    y+=dy[dir];
                    if(x>=0 && x<r && y>=0 && y<c){
                        ans.push_back({x, y});
                    }
                    if(ans.size() == total) return ans;
                }

                dir=(dir+1)%4;
            }
            len++; 
        }

        return ans;
    }
};