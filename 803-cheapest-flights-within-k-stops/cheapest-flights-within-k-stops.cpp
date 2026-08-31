class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>>graph(n);

        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];

            graph[u].push_back({v,wt});
        }

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        >pq;

        // {cost,{stops,node}}
        pq.push({0,{0,src}});

        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0]=0;

        while(!pq.empty()){

            int cost=pq.top().first;
            int stops=pq.top().second.first;
            int node=pq.top().second.second;

            pq.pop();

            if(node==dst)return cost;

            if(stops==k+1)continue;

            for(auto it:graph[node]){

                int v=it.first;
                int wt=it.second;

                int newCost=cost+wt;

                if(newCost<dist[v][stops+1]){

                    dist[v][stops+1]=newCost;

                    pq.push({newCost,{stops+1,v}});
                }
            }
        }

        return -1;
    }
};