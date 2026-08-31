class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //make graph:::
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<times.size();i++){
            int u = times[i][0]-1; //making 0 indexed graph
            int v = times[i][1]-1; //making 0 indexed graph
            int wt = times[i][2]; 

            graph[u].push_back({v,wt});
        }

        k=k-1;

        // priority queue:::
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >q;
        q.push({0,k});// time ,src

        vector<int>dist(n,INT_MAX);
        dist[k]=0;

        while(!q.empty()){
            int node=q.top().second;
            int wt=q.top().first;

            q.pop();

            for(auto it:graph[node]){
                int v=it.first;
                int cost=it.second;

                int newCost = cost+wt;
                if(dist[v] > newCost){
                    dist[v]=newCost;
                    q.push({newCost,v});
                }
            }

        }  
              

        int maxi=INT_MIN;
        for(auto it:dist){
            if(it==INT_MAX)return -1;
            maxi=max(maxi,it);
        }
        return maxi;
    }
};