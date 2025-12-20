class Solution {
public:
    void solve(string s,vector<string>&ans,int i,int n,string temp,int dots){
        if(dots==4 && i==n){
            ans.push_back(temp.substr(0,temp.length()-1));
            return;
        }
        if(dots>4)return;

        for (int j = i; j < min(i+3, (int)s.length()); j++) {
            if (stoi(s.substr(i, j-i+1)) < 256 && (i == j || s[i] != '0')) {
                solve(s,ans, j+1,n, temp + s.substr(i, j-i+1) + ".", dots+1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        //0-255
        int n=s.size();
        //valid ips
        vector<string>ans;
        if(n>12)return ans;

        string temp;
        int i=0;
        int dots=0;
        solve(s,ans,i,n,temp,dots);
        return ans;
    }
};