class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int ans=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(i==k)
                q.push({tickets[i],1});
            else
                q.push({tickets[i],0});
        }
        while(!q.empty()){
            int t=q.front().first;
            int f=q.front().second;
            ans++;
            t--;
            if(t==0){
                q.pop();
                if(f==1)return ans;
            }else{
                q.pop();
                q.push({t,f});
            }
        }
        return ans;
    }
};