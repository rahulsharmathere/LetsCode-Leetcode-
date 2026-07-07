class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n=nums.size();
        //manacher for palindromes -> O(n) me krta hai
        vector<long long> pref(n+1,0);
        for(int i=0;i<n;i++)
            pref[i+1]=pref[i]+nums[i];

        auto sum=[&](int l,int r){
            return pref[r+1]-pref[l];
        };

        vector<int> odd(n);
        int l=0,r=-1;
        for(int i=0;i<n;i++){
            int k=(i>r)?1:min(odd[l+r-i],r-i+1);
            while(i-k>=0 && i+k<n && nums[i-k]==nums[i+k])
                k++;
            odd[i]=k;
            if(i+k-1>r){
                l=i-k+1;
                r=i+k-1;
            }
        }

        vector<int> even(n);
        l=0,r=-1;
        for(int i=0;i<n;i++){
            int k=(i>r)?0:min(even[l+r-i+1],r-i+1);
            while(i-k-1>=0 && i+k<n && nums[i-k-1]==nums[i+k])
                k++;
            even[i]=k;
            if(i+k-1>r){
                l=i-k;
                r=i+k-1;
            }
        }

        long long ans=0;

        for(int i=0;i<n;i++){
            int L=i-odd[i]+1;
            int R=i+odd[i]-1;
            ans=max(ans,sum(L,R));
        }

        for(int i=0;i<n;i++){
            if(even[i]==0) continue;
            int L=i-even[i];
            int R=i+even[i]-1;
            ans=max(ans,sum(L,R));
        }

        return ans;
    }
};