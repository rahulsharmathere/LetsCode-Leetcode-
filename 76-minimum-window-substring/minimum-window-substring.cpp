class Solution {
public:
    string minWindow(string s, string t) {
        // optimized
        int n=s.size();
        int m=t.size();
        if (n < m) return "";
        int minLen=INT_MAX;
        int startInd=-1;
        int cnt=0;
        int l=0;
        int r=0;
        map<char,int>hash;
        for(int j=0 ; j<m ; j++){
            hash[t[j]]++;
        }

        while(r<n){
            if(hash[s[r]]>0)cnt++;
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1 < minLen){
                    minLen=r-l+1;
                    startInd=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)cnt--;
                l++;
            }
            r++;
        }

        if(startInd==-1)return "";
        return s.substr(startInd,minLen);
    }
};