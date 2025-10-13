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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        //DSU QUESTION:::
        // to return edge that makes cycle or doublr parent issue
        int n=edges.size();
        vector<int>parent(n+1,0);
        vector<int>candA,candB;


        for(int i=0;i<n;i++){
            int u= edges[i][0];
            int v= edges[i][1];

            if(parent[v]==0)parent[v]=u;
            else{
                candA={parent[v],v}; // first parent
                candB={u,v}; //second parent
                edges[i][1]=0;//mark invalid
            }
        }
        disjointSet ds(n);
        for(int i=0;i<n;i++){
            if(edges[i][1] == 0)continue;
            int u=edges[i][0];
            int v=edges[i][1];

            if(ds.isConnected(u,v)){
                //cycle
                if(!candA.empty())
                    return candA;//remove first parent edge
                return {u,v};//remove this edge
            }
            ds.unionByRank(u,v);
        }

        //no cycle: remove second parent edge
        return candB;
    }
};