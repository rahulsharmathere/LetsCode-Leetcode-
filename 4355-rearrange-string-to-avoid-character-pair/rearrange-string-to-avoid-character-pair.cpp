class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        vector<int>hash(26,0);
        for(auto it:s){
            hash[it-'a']++;
        }
        string t="";
        for(int i=0 ; i<hash[y-'a'] ; i++)
            t+=y;
        hash[y-'a']=0;
        for(int i=0 ; i<hash[x-'a'] ; i++)
            t+=x;
        hash[x-'a']=0;
        
        
        for(int i=0;i<26;i++){
            while(hash[i]){
                t+=('a'+i);
                hash[i]--;
            }
        }
        return t;
    }
};