class disjointSet {
    private:
        vector<int>par;
        vector<int>rank;
    public:
        disjointSet(int n){
            par.resize(n);
            rank.resize(n,0);
            for(int i=0;i<n;i++)par[i]=i;
        }
        int findUltPar(int u){
            if(par[u]==u)return u;
            return par[u]=findUltPar(par[u]);
        }

        void unionByRank(int u,int v){
            int u_par=findUltPar(u);
            int v_par=findUltPar(v);
            if( u_par == v_par)return ;
            if(rank[u_par] < rank[v_par]){
                par[u_par]=v_par;
            }else if(rank[u_par] > rank[v_par]){
                par[v_par]=u_par;
            }else {
                par[v_par]=u_par;
                rank[u_par]++;
            }
        }

        bool isConnected(int u,int v){
            if(findUltPar(u) == findUltPar(v))return true;
            else return false;
        }
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        disjointSet uf(n);

        for (int i = 0; i < n; ++i) {
            int c1 = row[2 * i] / 2;
            int c2 = row[2 * i + 1] / 2;
            uf.unionByRank(c1, c2);
        }

        int connectedComponents = 0;
        for (int i = 0; i < n; ++i) {
            if (uf.findUltPar(i) == i) {
                connectedComponents++;
            }
        }

        return n - connectedComponents;
        
    }
};