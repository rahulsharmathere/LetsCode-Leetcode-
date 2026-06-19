class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        int maxLen=0;
        map<char,int>mp;
        while(r<n){
            while(mp.find(s[r])!=mp.end()){
                mp[s[l]]--;
                if(mp[s[l]]==0)mp.erase(s[l]);
                l++;
            }
            mp[s[r]]++;
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};