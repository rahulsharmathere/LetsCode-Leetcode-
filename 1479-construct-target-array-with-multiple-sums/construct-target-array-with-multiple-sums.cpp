class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
        priority_queue<int>pq;
        long long sum=0;
        for(auto it:target){
            pq.push(it);
            sum+=it;
        }
        
        while(true){
            long long maxx=pq.top();
            pq.pop();
            long long rest=sum-maxx;

            if(maxx==1 || rest==1)return true;
            if(rest==0 || maxx<rest)return false;

            long long prev=maxx % rest;
            if(prev==0)return false;
            pq.push(prev);
            sum=rest+prev;
        }
        return true;
        
    }
};