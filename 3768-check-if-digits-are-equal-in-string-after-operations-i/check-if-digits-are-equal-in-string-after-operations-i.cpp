class Solution {
public:
    bool hasSameDigits(string s) {
        //sum%10
        while(s.size()!=2){
            int n=s.size();
            string str="";
            for(int i=0;i<n-1;i++){
                str+=(s[i]+s[i+1])%10;
            }
            s=str;
        }
        return s[0]==s[1];
    }
};