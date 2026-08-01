class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        stack<int>st;
        st.push(0);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(0);                
            }else{
                int val = st.top();
                st.pop();

                int score = max(2 * val, 1);

                int prev = st.top();
                st.pop();
                st.push(score + prev);
            }
        }
        return st.top();
    }
};