class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(k==n)return "0";
        stack<char>st;
        for(int i=0;i<n;i++){
            char dig=num[i];
            while(!st.empty() && (st.top()) > dig  && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        string s;
        while(!st.empty()){
            char c=st.top();
            s.push_back(c);
            st.pop();
        }
        reverse(s.begin(),s.end());
        
        int i=0;
        while(i<s.size() && s[i]=='0')i++;
        s=s.substr(i); 

        return s.empty() ? "0" :s;
    }
};