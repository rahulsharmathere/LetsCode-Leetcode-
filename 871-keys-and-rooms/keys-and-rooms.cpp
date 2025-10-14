class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //BFS 
        int n=rooms.size();
        //given graph
        vector<int>vis(n,0);
        //call BFS for 0 , an check reachabilty
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:rooms[node]){
                if(vis[it]==0){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }   
        //check reachabbilty of every node from 0
    
        for(auto it:vis)if(it==0)return false;
        return true;
    
    }
    
};