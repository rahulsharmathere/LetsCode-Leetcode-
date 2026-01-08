class Solution {
public:
    int helper(vector<int>&nums1,vector<int>&nums2,int i,int j,vector<vector<int>>&dp){
        if(i==nums1.size() || j==nums2.size()){
            return INT_MIN;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int curr=nums1[i]*nums2[j] ;
        //option1: take from 1 and from 2
        int opt1=helper(nums1,nums2,i+1,j+1,dp);
        if(opt1!=INT_MIN)curr=max(curr,curr+opt1);
        //option2: take from 1 and not from 2
        int opt2=helper(nums1,nums2,i,j+1,dp);
        //option3: take from 2 and not from 1
        int opt3=helper(nums1,nums2,i+1,j,dp);
        

        return dp[i][j]=max(curr,max(opt2,opt3));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        int i=0;
        int j=0;
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        int ans=helper(nums1,nums2,i,j,dp);

        return ans;
    }
};