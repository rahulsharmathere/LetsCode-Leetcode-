class Solution {
public:
    int numSub(string s) {
        const long long MOD=1e9+7;
        long long  ans=0;
        long long  cnt=0;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
            }
            if(s[i]=='0'){
                ans+=(cnt*(cnt+1)/2)%MOD;
                cnt=0;
            }

        }
        return (ans+cnt*(cnt+1)/2)%MOD;
    }
};