class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long ans=0;
        long long len=1;
        for(int i=1;i<n;i++){
            if(prices[i]==prices[i-1]-1){
                len++;
            }
            else {
                ans+=(len*(len+1))/2;
                len=1;
            }
        }
        ans+=(len*(len+1))/2;

        return ans;
    }
};