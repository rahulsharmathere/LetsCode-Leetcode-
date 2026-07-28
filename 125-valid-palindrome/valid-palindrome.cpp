class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string t;
        for(auto c:s){
            if((c>='A' && c<='Z')||(c>='a' && c<='z'))
                t+=tolower(c);
            else if(c>='0' && c<='9')
                t+=c;
            else continue;
        }
        int i=0;
        int j=t.size()-1;
        while(i<j){
            if(t[i]!=t[j])return false;
            i++;
            j--;
        }
        return true;
            
    }
};