class disjointSet{
    vector<int>par;
    vector<int>rank;
    public:
    disjointSet(int n){
        rank.resize(n+1,0);
        par.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }
    int ultPar(int u){
        if(par[u]==u)return u;
        return par[u] = ultPar(par[u]);
    }
    bool isConnected(int u,int v){
        if(ultPar(u)==ultPar(v))return true;
        return false;
    }
    void unionByRank(int u,int v){
        int ultPar_u = ultPar(u);
        int ultPar_v = ultPar(v);

        if(ultPar_u==ultPar_v)return;
        else if(rank[ultPar_u] > rank[ultPar_v]){
            par[ultPar_v]=ultPar_u;
        }else if(rank[ultPar_u] < rank[ultPar_v]){
            par[ultPar_u]=ultPar_v;
        }else{
            par[ultPar_u]=ultPar_v;
            rank[ultPar_v]++;
        }
    
    }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //DSU QUESTION:::
        //cycle edge is etected when an edge is trying to connect already connected components
        int n=edges.size();
        disjointSet ds(n);
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(ds.isConnected(u,v)==false){
                ds.unionByRank(u,v);
            }
            else{
                st.push({u,v});
            }
        }
        vector<int>ans;
        ans.push_back(st.top().first);
        ans.push_back(st.top().second);
        return ans;
    }
};