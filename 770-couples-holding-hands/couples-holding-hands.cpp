class disjointSet{
    public:
        vector<int>par;
        vector<int>size;
        disjointSet(int n){
            size.resize(n,1);
            par.resize(n);
            for(int i=0;i<n;i++)par[i]=i;
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
    int minSwapsCouples(vector<int>& row) {
        int n=row.size()/2;
        disjointSet ds(2*n);

        for(int i=0;i<2*n;i+=2){
            ds.unionBySize(i,i+1);
        }
        for(int i=0;i<2*n;i+=2){
            ds.unionBySize(row[i],row[i+1]);
        }

        unordered_map<int, unordered_set<int>> compToCouples;
        for(int i=0;i<2*n;i++){
            int parent = ds.ultPar(i);
            int couple_id = i / 2; // each couple = (2k, 2k+1)
            compToCouples[parent].insert(couple_id);
        }

        int swaps = 0;
        for (auto &p : compToCouples)
            swaps += (int)p.second.size() - 1;

        return swaps;



    }
};