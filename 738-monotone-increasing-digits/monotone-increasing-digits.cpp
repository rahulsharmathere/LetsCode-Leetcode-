class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s=to_string(n);
        int ind=0;
        int num=s[0];
        int i;
        for(i=1;i<s.size();i++){
            if(s[i]==num)continue;
            if(s[i]>num){
                num=s[i];
                ind=i;
            }
            else{
                break;
            }
        }
        if(i==s.size()){
            int ans=stoi(s);
            return ans;
        }
        s[ind]=num-1;
        for(int j=ind+1;j<s.size();j++){
            s[j]='9';
        }
        int ans=stoi(s);
        return ans;
    }
};