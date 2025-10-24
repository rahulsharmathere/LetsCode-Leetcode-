class Solution {
public:
    bool canPartition(vector<int>& arr) {
        // if you can find a sum of target=nums/2 in this array
        int n=arr.size();
        int i=0;
        int sum=0;
        for(auto it:arr)sum+=it;
        if(sum%2!=0)return false;
        sum=sum/2;
        vector<vector<bool>>DP(n,vector<bool>(sum+1,false));
        //base
        for(int i=0;i<n;i++)DP[i][0]=true;
        if(arr[0]<=sum)DP[0][arr[0]]=true;

        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool take = false;
                if(target >= arr[i]) {
                    take = DP[i-1][target-arr[i]];
                }
                bool leave=DP[i-1][target];
                
                DP[i][target] = (take||leave);
            }
        }

        return DP[n-1][sum];
    }
};