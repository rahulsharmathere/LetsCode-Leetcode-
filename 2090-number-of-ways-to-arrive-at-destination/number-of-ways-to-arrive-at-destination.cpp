class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        // start 0 -  destiniation n-1
        //making graph:::

        vector<vector<pair<int,int>>> graph(n);
        for(int i=0 ; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            graph[u].push_back({v,w});
            graph[v].push_back({u,w});//bidirectional hai;
        }
        
        priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>> >pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});

  
        while(!pq.empty()){
            long long d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if (d > dist[node]) continue; 

            for(auto it:graph[node]){
                int v=it.first;
                int w=it.second;
                long long newDist = d + w;

                if(dist[v] > newDist){
                    dist[v]=w+d;
                    ways[v] = ways[node];
                    pq.push({newDist, v});
                }
                else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[node]) % MOD;
                }

            }
        }
        return ways[n - 1] % MOD;
    }
};