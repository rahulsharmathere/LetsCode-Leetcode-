class Solution {
public:
    bool solve(vector<int>&arr,int sum,int i,vector<vector<int>>&DP){
        int n=arr.size();
        if(sum==0)return true;
        if(i>=n-1)return (arr[i]==sum);
        if(DP[i][sum]!=-1)return DP[i][sum];
        //take
        bool opt1 = false;
        if(sum>=arr[i])
             opt1=solve(arr,sum-arr[i],i+1,DP);
        
        //not take
        bool opt2 = solve(arr,sum,i+1,DP);
        
        return DP[i][sum]=(opt1 || opt2);
    }
    bool canPartition(vector<int>& arr) {
        // if you can find a sum of target=nums/2 in this array
        int n=arr.size();
        int i=0;
        int sum=0;
        for(auto it:arr)sum+=it;
        if(sum%2!=0)return false;
        sum=sum/2;
        vector<vector<int>>DP(n,vector<int>(sum+1,-1));
        return solve(arr,sum,i,DP);
    }
};