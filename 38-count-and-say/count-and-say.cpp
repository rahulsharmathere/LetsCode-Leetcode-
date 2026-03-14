class Solution {
public:
    string rle(string s){
        int n=s.size();
        string str="";
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt++;
            if(i==n-1 || s[i+1]!=s[i]){
                string st=to_string(cnt);
                str+=st;
                str+=s[i];
                cnt=0;
            }
        }

        return str;
    }
    string countAndSay(int n) {
        if(n==1){
            string s="1";
            return s;
        }
        return rle(countAndSay(n-1));
    }
};