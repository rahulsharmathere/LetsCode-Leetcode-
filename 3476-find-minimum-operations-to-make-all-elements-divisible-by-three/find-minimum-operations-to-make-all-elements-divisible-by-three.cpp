class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int num=nums[i]%3;
            num=min(num,3-num);
            cnt+=num;
        }
        return cnt;
    }
};