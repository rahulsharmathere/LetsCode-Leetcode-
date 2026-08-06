class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push({it->second,it->first});
        }
        string ans="";
        while(!pq.empty()){
            int num=pq.top().first;
            char c=pq.top().second;
            while(num--){
                ans+=c;
            }
            pq.pop();
        }
        return ans;
    }
};