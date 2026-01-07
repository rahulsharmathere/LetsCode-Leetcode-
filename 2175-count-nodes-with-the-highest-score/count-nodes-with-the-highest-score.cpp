class Solution {
public:
    int dfs(int node,vector<int>&size,int n,vector<vector<int>>&tree){
        int currSize=1;
        for (int child : tree[node]) {
            int sub = dfs(child,size,n,tree);
            currSize += sub;
        }
        size[node]=currSize;
        return currSize;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();//no of nodes
        vector<vector<int>>tree(n);//ele->children
        for(int i=1;i<n;i++){
            tree[parents[i]].push_back(i);
        }
        vector<int>size(n);
        size[0]=n;

        dfs(0,size,n,tree);

        int count=0;
        long long maxScore=INT_MIN;
        for(int i=0;i<n;i++){
            long long score=1;
            for(int j=0;j<tree[i].size();j++){
                score*=size[tree[i][j]];
            }
            int rest=n-size[i];
            if(rest>0)score*=rest;
            if(score>maxScore){
                maxScore=score;
                count=1;
            }else if(score==maxScore){
                count++;
            }
        }
        return count;
    }
};