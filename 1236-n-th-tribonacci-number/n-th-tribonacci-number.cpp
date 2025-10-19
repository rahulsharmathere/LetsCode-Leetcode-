class Solution {
public:
    int fun(int i,vector<int>&DP){
        if(i==0)return 0;
        if(i==1)return 1;
        if(i==2)return 1;
        if(DP[i]!=-1)return DP[i];

        return DP[i]=fun(i-1,DP)+fun(i-2,DP)+fun(i-3,DP);
    }
    int tribonacci(int n) {
        vector<int>DP(n+1,-1);
        return fun(n,DP);
    }
};