class Solution {
public:
    void solve(vector<string>&arr,int i,int &len,string s){
        if(i==arr.size())return;
        string t=arr[i];
        bool flag=true;
        vector<int>check(26,0);
        for(int i=0;i<s.size();i++){
            check[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            if(check[t[i]-'a']>0){
                flag=false;
            }
            check[t[i]-'a']++;
        }
        if(flag){
            s+=t;
            len = max(len, (int)s.size());
            solve(arr,i+1,len,s);
            for(int i=0;i<t.size();i++)s.pop_back();
            solve(arr,i+1,len,s);

        
        }else{
            solve(arr,i+1,len,s);
        }

    }

    int maxLength(vector<string>& arr) {
        int n=arr.size();
        int len=0;
        int i=0;
        string s="";
        solve(arr,i,len,s);
        return len;
    }
};