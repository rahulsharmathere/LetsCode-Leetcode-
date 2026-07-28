class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<int>hash(26,0);
        for(int i=0;i<n/2;i++){
            hash[s[i]-'a']++;
        }
        string ans="";
        for(int i=0;i<26;i++){
            while(hash[i]--)ans+=(char)('a'+i);
        }
        string temp=ans;
        reverse(temp.begin(),temp.end());
        if(n%2!=0){
            ans+=s[n/2];
        }
        ans.append(temp);
        return ans;

    }
};