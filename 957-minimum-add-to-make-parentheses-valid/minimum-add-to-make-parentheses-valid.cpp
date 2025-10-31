class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        if(n==0)return 0;//valid
        stack<char>st;
        for(auto it:s){
            if(st.empty()){
                st.push(it);
                continue;
            }
            if(it==')' && st.top()=='(' ){
                st.pop();
                continue;
            }
            st.push(it);
        }

        return st.size();

    }
};