class Solution {
public:
    vector<int>solve(string s){
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                vector<int>leftAns=solve(s.substr(0,i));
                vector<int>rightAns=solve(s.substr(i+1,s.size()-1));
                for(int &x:leftAns){
                    for(int &y:rightAns){
                        if(s[i]=='+'){
                            ans.push_back(x+y);
                        }
                        if(s[i]=='-'){
                            ans.push_back(x-y);
                        }
                        if(s[i]=='*'){
                            ans.push_back(x*y);
                        }
                    }
                }
            }
        }
        if(ans.empty()){
            ans.push_back(stoi(s));
        }
        return ans;
    }

    vector<int> diffWaysToCompute(string s) {
        return solve(s);

    }
};