class Solution {
public:
    void dfs(int i,vector<vector<int>>&graph,vector<int>&vis,vector<int>&result,bool &hasCycle){
        if(vis[i]==1){hasCycle=true;return;}
        if(vis[i]==2)return;

        vis[i]=1;
        for(auto it:graph[i]){
            dfs(it,graph,vis,result,hasCycle);
            if(hasCycle)return;
        }
        vis[i]=2;
        result.push_back(i);
    }
    vector<int> toposort(vector<vector<int>>&graph){
        int n=graph.size();
        vector<int>vis(n,0);// 0->not vis , 1->curr path , 2->fully processed
        vector<int>result;
        bool hasCycle=false;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,graph,vis,result,hasCycle);
            }
        }
        if(hasCycle)return {};
        reverse(result.begin(),result.end());
        return result;

    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // if any cycle detected return []
        for(int i=0;i<n;i++){
            if(group[i]==-1){
                group[i]=m++;
            }
        }

        vector<vector<int>>itemGraph(n);
        vector<vector<int>>groupGraph(m);

        for(int i=0;i<n;i++){
            for(auto it:beforeItems[i]){
                itemGraph[it].push_back(i);
                if(group[i]!=group[it]){
                    groupGraph[group[it]].push_back(group[i]);
                }
            }
        }

        vector<int>groupOrder=toposort(groupGraph);
        if(groupOrder.size()==0)return{};
        vector<int>itemOrder=toposort(itemGraph);
        if(itemOrder.size()==0)return{};

        unordered_map<int,vector<int>>groupToItems;
        for(int item:itemOrder){
            groupToItems[group[item]].push_back(item);
        }

        vector<int>ans;
        for(auto g:groupOrder){
            for(auto item:groupToItems[g]){
                ans.push_back(item); 
            }
        }
        return ans;

    }
};