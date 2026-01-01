class Solution {
public:

    void solve(string s,string mapp[],vector<string>&ans,string&digits,int index){
        if(index>=digits.length()){
            ans.push_back(s);
            return;
        }
        int number=digits[index]-'0';
        string value=mapp[number];
        for(int i=0;i<value.length();i++){
            s.push_back(value[i]);
            solve(s,mapp,ans,digits,index+1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<string>ans;
        if(n==0)return ans;
        string s="";
        string mapp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        solve(s,mapp,ans,digits,0);
        return ans;
    }
};