class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // power set
        vector<vector<int>>ans;
        int n=nums.size();
        int subsets = 1<<n;//this is 2^n -> no of subsets
        for(int num=0 ; num<subsets ; num++){
            vector<int>list;
            for(int i=0;i<n;i++){
                if(num & (1<<i)){
                    list.push_back(nums[i]);
                }
            }
            ans.push_back(list);
        }
        return ans;
    }
};