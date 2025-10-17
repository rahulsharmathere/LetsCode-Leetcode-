class disjointSet{
    public:
        vector<int>par;
        vector<int>size;
        disjointSet(int n){
            size.resize(n+1,1);
            par.resize(n+1);
            for(int i=1;i<=n;i++)par[i]=i;
        }
        void unionBySize(int u,int v){
            int parU=ultPar(u);
            int parV=ultPar(v);
            if(parU==parV)return;
            
            if(size[parU] < size[parV]){
                par[parU]=parV;
                size[parV]+=size[parU];
            }
            else{
                par[parV]=parU;
                size[parU]+=size[parV];
            }
            
        }
        bool isConnected(int u,int v){
            return (ultPar(u)==ultPar(v));
        }
        int ultPar(int u){
            if(u==par[u])return u;
            return par[u]=ultPar(par[u]);
        }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        

        disjointSet ds(n);
        int ans=INT_MAX;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int d=roads[i][2];
            ds.unionBySize(u,v);

        }
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int d=roads[i][2];
            // ds.unionBySize(u,v);
            if(ds.isConnected(1,u))ans=min(ans,d);
            
        }
        return ans;

    }
};