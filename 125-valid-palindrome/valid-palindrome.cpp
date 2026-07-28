class Solution {
public:
    bool isPalindrome(string s) {
        int k=0;
        vector<char>s2(s.size(),' ');

        while(k<s.size()){
            if(s[k]>=65 && s[k]<=90){
                s2[k]=s[k]+32;
            }
            else if(s[k]>=97 && s[k]<=122){
                s2[k]=s[k];
            }
            else if(s[k]<=57 && s[k]>= 48){
                s2[k]=s[k];
            }else{
                s2[k]=' ';
            }
            k++;
        }
        int i=0;
        int j=s2.size()-1;
        while(i<j){
            if(s2[i]==' '){
                i++;
                continue;
            }
            if(s2[j]==' '){
                j--;
                continue;
            }
            if(s2[i]!=s2[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};