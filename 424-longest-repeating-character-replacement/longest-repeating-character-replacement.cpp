class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0;
        int r=0;
        unordered_map<char,int>mp;
        int maxf=0;
        int maxlen=0;
        while(r<n){
            mp[s[r]]++;
            maxf=max(maxf,mp[s[r]]);
            

            while((r-l+1)-maxf>k){
                mp[s[l]]--;
                maxf=0;
                for(auto it:mp)maxf=max(maxf,it.second);
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
            
        }
        return maxlen;
    }
};