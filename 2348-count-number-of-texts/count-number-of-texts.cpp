class Solution {
public:
    

    int countTexts(string s) {
        int mod=1e9+7;
        int n=s.size();
        vector<int>DP(n+1,0);
        DP[n]=1;

        for(int i=n-1;i>=0;i--){
            // one key
            long long opt1=DP[i+1]%mod;
            long long opt2=0;
            long long opt3=0;
            long long opt4=0;

            if(i+1<n && s[i]==s[i+1]){
                opt2=DP[i+2]%mod;
            }
            if(i+2<n && s[i]==s[i+2] && s[i]==s[i+1]){
                opt3=DP[i+3]%mod;
            }
            if(i+3<n && s[i]==s[i+2] && s[i]==s[i+1] && s[i]==s[i+3] && (s[i]=='7'||s[i]=='9')){
                opt4=DP[i+4]%mod;
            }

            DP[i]=(opt1+opt2+opt3+opt4)%mod;
        }
        return (int)DP[0];
    }
};