class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++){
            int cnt=0;
            cnt=__builtin_popcount(i);
            ans[i]=cnt;
        }
        return ans;
    }
};