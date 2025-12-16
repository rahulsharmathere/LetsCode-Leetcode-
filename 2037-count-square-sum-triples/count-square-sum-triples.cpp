class Solution {
public:
    int countTriples(int n) {
        vector<int>nums(n+1);
        for(int i=1;i<=n;i++){
            nums[i]=i*i;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int sum=nums[i]+nums[j];
                for(int k=j+1;k<=n;k++){
                    if(sum==nums[k])ans++;
                }
            }
        }
        return ans*2;
    }
};