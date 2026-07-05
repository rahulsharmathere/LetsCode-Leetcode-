class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int maxRange=-1;
        for(int i=0;i<n;i++){
            int range;
            int x=nums[i];
            int mini=10;
            int maxi=0;
            while(x>0){
                int dig=x%10;
                x=x/10;
                mini=min(mini,dig);
                maxi=max(maxi,dig);
            }
            range=maxi-mini;
            if(maxRange<range){
                maxRange=range;
                ans=nums[i];
            }else if(maxRange==range){
                ans+=nums[i];
            }
        }
        return ans;
    }
};