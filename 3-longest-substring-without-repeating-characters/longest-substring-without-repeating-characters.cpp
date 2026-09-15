class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        int maxLen=0;
        unordered_map<char,int>mp;
        while(r<n){
            while(mp[s[r]]!=0){
                mp[s[l]]--;
                l++;
            }
            mp[s[r]]++;
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};