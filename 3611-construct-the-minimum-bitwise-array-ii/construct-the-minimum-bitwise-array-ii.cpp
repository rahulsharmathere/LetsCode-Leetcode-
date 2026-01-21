class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            int ans=-1;
            for(int j=31; j>=0; j--){
                if(nums[i] & (1<<j)){
                    int num = nums[i]-(1<<j);
                    if((num|(num+1))==nums[i]){
                        if (ans == -1) ans = num;
                        else ans = min(ans, num);
                    }
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};