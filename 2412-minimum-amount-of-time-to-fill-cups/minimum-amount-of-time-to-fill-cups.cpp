class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans = 0; 
        int n=amount.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(amount[i]);
        }
        while(!pq.empty()){
            if(pq.top()<=0)break;
            ans++;
            int curr1=pq.top();
            curr1--;
            pq.pop();
            int curr2=0;
            if(!pq.empty()){
                curr2=pq.top();
                curr2--;
                pq.pop();
            }
            if(curr1)pq.push(curr1);
            if(curr2)pq.push(curr2);
        }
        
        return ans;
    }
};