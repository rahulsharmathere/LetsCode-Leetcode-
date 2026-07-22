class Solution {
public:
    bool dfs(int sx,int sy,int tx,int ty,int moves,vector<vector<bool>>&visited){
        int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-1,-2},{-2,-1},{1,-2},{2,-1}};
        if(sx<0 || sx>=8 || sy<0 || sy>=8 || visited[sx][sy])return false;
        if(sx==tx && sy==ty)return (moves%2==0);
        visited[sx][sy]=true;
        for(int i=0;i<8;i++){
            int nx=sx+dir[i][0];
            int ny=sy+dir[i][1];
            if(dfs(nx,ny,tx,ty,moves+1,visited)==true)return true;
        }
        return false;
    }
    bool canReach(vector<int>& start, vector<int>& target) {
        int sx=start[0];
        int sy=start[1];
        int tx=target[0];
        int ty=target[1];
        int moves=0;       
        vector<vector<bool>>visited(8,vector<bool>(8,false));
        return dfs(sx,sy,tx,ty,moves,visited);
    }
};