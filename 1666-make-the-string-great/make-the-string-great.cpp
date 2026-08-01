class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        if(n==0)return s;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(!st.empty() && abs(st.top()-s[i])==32){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;

    }
};