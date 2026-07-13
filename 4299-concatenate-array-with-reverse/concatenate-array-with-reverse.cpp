class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
      vector<int> ans;
        int i=0,j=1,n=nums.size();
        while(i<2*n){
            if(i<n){
                ans.push_back(nums[i]);
            }
            else{
                ans.push_back(nums[i-j]);
                j+=2;
            }
            i++;
        }
        return ans;
    }
};