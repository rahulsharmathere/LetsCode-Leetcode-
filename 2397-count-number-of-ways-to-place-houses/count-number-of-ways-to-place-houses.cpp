class Solution {
public:
    long long fun(int n,bool prevHouse,vector<vector<long long>>&DP){
        int mod=1e9+7;
        if(n==0)return 1;
        if(DP[n][prevHouse]!=-1)return DP[n][prevHouse];

        long long ways=0;
        ways=fun(n-1,false,DP) % mod;

        if(!prevHouse)
            ways=(ways+fun(n-1,true,DP)) % mod;

        return DP[n][prevHouse]=ways;
    }
    int countHousePlacements(int n) {
        int MOD=1e9+7;
        vector<vector<long long>>DP(n+1,vector<long long>(2,-1));

        long long oneSide=fun(n,false,DP)%MOD;
        return (oneSide*oneSide)%MOD;
    }
};