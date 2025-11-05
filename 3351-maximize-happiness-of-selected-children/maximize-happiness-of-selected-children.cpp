class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long taken=0;
        long long ans=0;
        for(int i = 0; i < k; i++){
            if(taken>=k)break;
            long long val=happiness[i]-taken;
            if (val <= 0) break;
            ans+=val;
            taken++;
        }

        return ans;

    }
};