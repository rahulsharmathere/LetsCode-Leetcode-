class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](auto& a,auto& b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        int n=envelopes.size();
        vector<int> tails;
        for(int i=0;i<n;i++){
            int k=envelopes[i][1];
            if(tails.empty() || tails.back()<k)
                tails.push_back(k);
            else
            {
                auto it = lower_bound(tails.begin(),tails.end(),k);
                *it=k;
            }
        }
        return tails.size();
    }
};