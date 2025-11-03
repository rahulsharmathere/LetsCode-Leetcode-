class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=s.size();
        vector<int>hash(26,0);
        vector<int>hash2(26,0);
        for(int i=0;i<n;i++){
            //0->a
            int ind=s[i]-'a';
            hash[ind]++;
        }
        for(int i=0;i<=n;i++){
            int ind=t[i]-'a';
            hash2[ind]++;
        }
        for(int i=0;i<26;i++){
            if(hash[i]!=hash2[i])return (char)('a'+i);
        }
        return 'a';

    }
};