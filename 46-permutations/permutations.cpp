class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        ans.push_back(nums);
        vector<int>v(nums);
        next_permutation(v.begin(),v.end());
        while(nums!=v){
            ans.push_back(v);
            next_permutation(v.begin(),v.end());
        }
        return ans;
    }
};