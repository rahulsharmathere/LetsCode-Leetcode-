class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> freq(51, 0), ans;
        
        for(int i = 0, j = 0; i < n; i++) {
            if(nums[i] < 0) freq[abs(nums[i])]++;
            if(i - j + 1 >= k) {
                int cnt = 0;
                for(int L = 50; L >= 1; L--) {
                    cnt += freq[L];
                    if(cnt >= x) { ans.push_back(-L); break;}
                }
                if(cnt < x) ans.push_back(0);
                if(nums[j] < 0) freq[abs(nums[j])]--;
                j++;
            }
        }
        return ans;
        
    }
};