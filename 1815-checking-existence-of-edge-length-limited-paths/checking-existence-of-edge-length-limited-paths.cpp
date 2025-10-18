class disjointSet{
    vector<int>rank;
    vector<int>par;
    vector<int>size;
public:
    disjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        par.resize(n+1); 
        
        for(int i=0;i<n;i++){
            par[i]=i;
            
        }
    }
    
    int ultPar(int u){
        if(u==par[u])return u;
        return par[u]=ultPar(par[u]);
    }
    
    void unionByRank(int u,int v){
        int ultPar_u = ultPar(u);
        int ultPar_v = ultPar(v);
        
        if(ultPar_u==ultPar_v)return;
        if(rank[ultPar_u] < rank[ultPar_v]){
            par[ultPar_u]=ultPar_v;
        }
        else if(rank[ultPar_u] > rank[ultPar_v]){
            par[ultPar_v]=ultPar_u;
        }
        else {
            par[ultPar_v]=ultPar_u;
            rank[ultPar_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ultPar_u = ultPar(u);
        int ultPar_v = ultPar(v);
        
        if(ultPar_u==ultPar_v)return;
        if(size[ultPar_u] < size[ultPar_v]){
            par[ultPar_u]=ultPar_v;
            size[ultPar_v]+=size[ultPar_u];
        }
        else{
            par[ultPar_v]=ultPar_u;
            size[ultPar_u]+=size[ultPar_v];
        }
       
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {

        sort(edgeList.begin(), edgeList.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });

        vector<array<int,4>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i][2], queries[i][0], queries[i][1], i});
        }
        sort(q.begin(), q.end());

        disjointSet ds(n);
        vector<bool>ans(queries.size());
        int j=0;

        for(auto qr:q){
            int limit = qr[0], u = qr[1], v = qr[2], idx = qr[3];
            while (j < edgeList.size() && edgeList[j][2] < limit) {
                ds.unionByRank(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            ans[idx]=(ds.ultPar(u)==ds.ultPar(v));
        }
        return ans;


    }
};