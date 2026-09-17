class Solution {
public:

    void solve(vector<vector<string>>&ans,string s,vector<string>&curr,int index){
        if(index==s.size()){
            ans.push_back(curr);
            return;
        }

        for(int i=index;i<s.size();i++){
            if(isPalin(s,index,i)){
                curr.push_back(s.substr(index, i - index + 1));
                solve(ans,s,curr,i+1);
                curr.pop_back();
            }
        }
    }
    bool isPalin(string s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        int index=0;
        solve(ans,s,curr,index);
        return ans;
    }
};