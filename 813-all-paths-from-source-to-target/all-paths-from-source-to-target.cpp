class Solution {
public:

    void dfs(int i,vector<vector<int>>& graph,vector<int>&vis,vector<vector<int>>&ans,vector<int>&temp,int n){
        if(temp.back()==n-1){
            ans.push_back(temp);
            return;
        }

        vis[i]=1;
        for(auto it:graph[i]){
            if(vis[it]==0){
                temp.push_back(it);
                dfs(it,graph,vis,ans,temp,n);
                temp.pop_back();
            }
        }
        vis[i]=0;

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //DAG
        //given list
        int n=graph.size();
        vector<vector<int>>ans;
        //paths
        vector<int>temp;
        //one of the temperory paths
        vector<int>vis(n);

        int startNode=0;
        temp.push_back(0);
        dfs(startNode,graph,vis,ans,temp,n);
        return ans;

    }
};