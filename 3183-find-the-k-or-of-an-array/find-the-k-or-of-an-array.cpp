class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<32;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                int num=nums[j];
                if(num & (1<<i)){
                    cnt++;
                }
            }
            if(cnt>=k){
                ans=ans|(1<<i);
            }
        }
        return ans;
    }
};