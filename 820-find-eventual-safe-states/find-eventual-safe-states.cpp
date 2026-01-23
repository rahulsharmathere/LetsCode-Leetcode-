class Solution {
public:
    bool dfs(vector<vector<int>>&graph,vector<int>&vis,vector<int>&pathVis,vector<int>&mark,int node){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(graph,vis,pathVis,mark,it)){
                    mark[node]=0;
                    return true;
                }
            }else if(pathVis[it]==1){
                mark[node]=0;
                return true;
            }
        }

        pathVis[node]=0;
        mark[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        vector<int>mark(n,0);

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(graph,vis,pathVis,mark,i);
            }
        }
        vector<int>safeNodes;
        for(int i=0;i<n;i++){
            if(mark[i]==1)safeNodes.push_back(i);
        }
        return safeNodes;
    }
};