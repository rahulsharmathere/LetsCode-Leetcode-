class Solution {
public:
    bool isPossible(vector<int>&candies,int num,long long k){
        long long sum=0;
        for(auto it:candies){
            sum+=it/num;
            if (sum >= k) return true;
        }
        if(sum>=k)return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        // int maxi=INT_MIN;
        // for(auto it:candies)maxi=max(maxi,it);
        int l=1;
        int h=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(l<=h){
            int m=l-(l-h)/2;
            if(isPossible(candies,m,k)){
                ans=m;
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return ans;
    }
};