class Solution {
public:
    void solve(vector<string>&ans,string &s,int i){
        if(i==s.size()){
            ans.push_back(s);
            return;
        }
        if(isdigit(s[i])){
            solve(ans,s,i+1);
            return;
        }
        //upper
        char c=s[i];
        s[i]=toupper(s[i]);
        solve(ans,s,i+1);
        s[i]=c;

        //lower
        c=s[i];
        s[i]=tolower(s[i]);
        solve(ans,s,i+1);
        s[i]=c;

    
    }
    vector<string> letterCasePermutation(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            s[i]=tolower(s[i]);
        }
        vector<string>ans;
        solve(ans,s,0);
        return ans;
    }
};