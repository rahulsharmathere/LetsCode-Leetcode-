class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int maxi=0;
        vector<int>pre(n+1);
        pre[0]=0;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+gain[i-1];
            maxi=max(pre[i],maxi);
        }
        return maxi;

    }
};