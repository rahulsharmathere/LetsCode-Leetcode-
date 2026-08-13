class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxi = 0;
        for(int i=0;i<s.length();i++){
            unordered_map<int,int> mp; 
            int cnt = 0;
            for(int j=i;j<s.length();j++){
                mp[s[j]-'a']++;
                if(mp[s[j]-'a']==k){
                    cnt++;
                }
                if(cnt == mp.size()){
                    maxi = max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};