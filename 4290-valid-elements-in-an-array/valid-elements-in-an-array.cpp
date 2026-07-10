class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> post(n);
        int prefix = 0, postfix = 0;

        for(int i=0;i<n;i++){
            prefix = max(prefix,nums[i]);
            postfix = max(postfix,nums[n-i-1]);
            pre[i] = prefix;
            post[n-i-1] = postfix;
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(i == 0 || i == n-1){
                ans.push_back(nums[i]);
                continue;
            }

            if(pre[i-1] < nums[i]) ans.push_back(nums[i]);
            else if(post[i+1] < nums[i]) ans.push_back(nums[i]);
        }

        return ans;
    }
};