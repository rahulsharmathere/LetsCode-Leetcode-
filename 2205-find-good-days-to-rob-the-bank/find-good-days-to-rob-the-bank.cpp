class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int k) {
        int n=security.size();
        // atleast k before and k after
        // all k ele on left >= x
        // all k ele on right >= x
        vector<int>pre(n,0);
        vector<int>post(n,0);
        for(int i=1,j=n-2 ; i<n ; i++,j--){
            if(security[i]<=security[i-1])pre[i]=pre[i-1]+1;
            if(security[j]<=security[j+1])post[j]=post[j+1]+1;
        }
        vector<int>ans;
        for(int i=k;i<n-k;i++){
            if(pre[i]>=k && post[i]>=k)ans.push_back(i);
        }
        return ans;

    }
};