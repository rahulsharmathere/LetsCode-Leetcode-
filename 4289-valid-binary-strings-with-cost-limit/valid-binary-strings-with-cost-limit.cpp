class Solution {
public:
    void valid(vector<string>&ans,int k,int n,int i,bool cons,string &str,int cost){
        if(cons)return;
        if(cost>k)return;
        if(i==n){
            ans.push_back(str);
            return;
        }
        str.push_back('0');
        valid(ans,k,n,i+1,cons,str,cost);
        str.pop_back();
        if(i>0 && str[i-1]=='1')cons=true;
        str.push_back('1');
        valid(ans,k,n,i+1,cons,str,cost+i);
        str.pop_back();


    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        string str;
        int cost=0;
        valid(ans,k,n,0,false,str,cost);
        return ans;
    }
};