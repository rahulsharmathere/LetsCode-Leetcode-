class Solution {
public:
    void dfs(int time,map<int,vector<int>>&adj,vector<int>&tin,vector<int>&low,vector<vector<int>>&ans,map<int,bool>&vis,int node,int par){
        vis[node]=true;
        tin[node]=time;
        low[node]=time;
        time++;

        for(auto it:adj[node]){
            if(it==par)continue;
            if(!vis[it]){
                dfs(time,adj,tin,low,ans,vis,it,node);
                low[node]=min(low[node],low[it]);
                if( low[it]>tin[node])ans.push_back({it,node});
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        map<int,vector<int>>adj;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>tin(n,-1);//time of insertion
        vector<int>low(n,-1);//lowest tin of all adj nodes (except parent)
        vector<vector<int>>ans;
        map<int,bool>vis;
        dfs(1,adj,tin,low,ans,vis,0,-1);
        return ans;
    }
};