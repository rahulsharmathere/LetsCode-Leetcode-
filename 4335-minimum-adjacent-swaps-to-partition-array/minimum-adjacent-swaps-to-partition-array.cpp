class Solution {
public:
    const int MOD=1e9+7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        long long swaps=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<a)nums[i]=0;
            else if(nums[i]>b)nums[i]=2;
            else nums[i]=1;
        }
        //cnt for 0
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                swaps+=cnt;
            }
            else cnt++;
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==2){
                swaps+=cnt;
            }
            else if(nums[i]==1)cnt++;
        }
        return swaps%MOD;
    }
};