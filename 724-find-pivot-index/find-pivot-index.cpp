class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        vector<int>prefix(n);
        vector<int>suffix(n);
        if(n==1 )return 0;
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];
        }
        if(n>1 && suffix[1]==0)return 0;
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            if(i<n-1 && prefix[i-1]==suffix[i+1])return i;
            prefix[i]=prefix[i-1]+nums[i];
        }
        if(n>1 && prefix[n-2]==0)return n-1;
        return -1;
        
    }
};