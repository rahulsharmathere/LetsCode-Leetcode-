class Solution {
public:

    int dfs(int i,vector<vector<int>>&graph,vector<int>&quiet,vector<int>&ans){
        if(ans[i]!=-1)return ans[i];
        
        int mini=i;
        for(auto it:graph[i]){
            int candidate=dfs(it,graph,quiet,ans);
            if(quiet[candidate]<quiet[mini])
                mini=candidate;
        }
        return ans[i]=mini;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        //reverse all the edges , ans[x]= that value reachable from x and has minimum quieteness
        //given no acyclic , no vis needed for dfs
        int n=quiet.size();
        vector<vector<int>>graph(n);
        for(int i=0;i<richer.size();i++) {
            int u = richer[i][1];
            int v = richer[i][0];

            graph[u].push_back(v); // adding reverse edge as given
        } 
        vector<int>ans(n,-1);//DYNAMIC PROGRAMMING

        
        for(int i=0;i<n;i++){
            dfs(i,graph,quiet,ans);
        }
        return ans;
    }
};