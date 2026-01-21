class Solution {
public:
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> graph;
        unordered_map<string, bool> visited;
        int n = equations.size();
        for(int i=0;i<n;i++){
            string divident=equations[i][0];
            string divisor=equations[i][1];
            double res=values[i];
            visited[divident] = false;
            visited[divisor] = false;
            graph[divisor][divident]=1/res;
            graph[divident][divisor]=res;

        }
        vector<double> res;
        int m = queries.size();
        for(int i=0;i<m;i++){
            for(auto &it : visited){
                it.second = false;
            }
            queue<pair<string,double>>q;
            string start = queries[i][0];
            string end = queries[i][1];
            if(!graph.count(start) || !graph.count(end)){
                res.push_back(-1.0);
                continue;
            }
            visited[start] = true;
            q.push({start, 1});
            double ans = -1;
            while(!q.empty()){
                string node = q.front().first;
                double cost = q.front().second;
                q.pop();
                if(node == end){
                    ans = cost;
                    break;
                }
                for(auto &it : graph[node]){
                    string dest = it.first;
                    double paise = it.second;
                    if(!visited[dest]){
                        q.push({dest, cost*paise});
                        visited[dest] = true;
                    }
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};