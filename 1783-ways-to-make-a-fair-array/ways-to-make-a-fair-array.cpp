class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        int evenSum=0;
        int oddSum=0;
        vector<int>sums(n,0);
        for(int i=n-1;i>=0;i--){
            if(i%2==0){
                evenSum+=nums[i];
                sums[i]=evenSum;
            }else{
                oddSum+=nums[i];
                sums[i]=oddSum;
            }
        }
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(i%2==1){
                int preveven=(i+1<n)?sums[i+1]:0;
                int prevodd=(i+2<n)?sums[i+2]:0;
                int neweven=evenSum-preveven+prevodd;
                int newodd=oddSum-nums[i]+preveven-prevodd;
                if(neweven==newodd )ans++;
            }else{
                int preveven=(i+2<n)?sums[i+2]:0;
                int prevodd=(i+1<n)?sums[i+1]:0;
                int neweven=evenSum-nums[i]-preveven+prevodd;
                int newodd=oddSum+preveven-prevodd;
                if(neweven==newodd )ans++;
            }

        }
        return ans;
    }
};