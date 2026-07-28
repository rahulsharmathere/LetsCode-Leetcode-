class Solution {
public:
    int countSubstrings(string s) {
        string t="#";
        for (char c:s) {
            t+=c;
            t+='#';
        }
        int cnt=0;
        for (int i=0;i<t.size();i++){
            int j=i;
            int k=i;
            while (j>=0 && k<t.size() && t[j]==t[k]){
                if(t[j]!='#')   
                    cnt++;
                j--;
                k++;
            }
        }
        return cnt;
    }
};