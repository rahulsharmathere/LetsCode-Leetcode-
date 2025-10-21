class Solution {
public:
    int solve(string s,int n,int i,vector<int>&DP){
        if(i==n)return 1;
        if(s[i]=='0')return 0;
        if(DP[i]!=-1) return DP[i];

        //2options : take this only , or take this and next
        int opt1 = solve(s,n,i+1,DP);
        int opt2=0;

        if(i+1 < n){
            int a=s[i]-'0';
            int b=s[i+1]-'0';
            int num=(a*10)+b;
            if(10<=num && num<=26){
                opt2 = solve(s,n,i+2,DP);
            }
        }
        return DP[i]=opt1+opt2;

    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>DP(n,-1);
        int i=0;
        return solve(s,n,i,DP);
    }
};