class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]!=']')
                st.push(s[i]);
            else{
                string str="";
                while(st.top()!='['){
                    str=st.top()+str;
                    st.pop();
                }st.pop();
                string num="";
                while(!st.empty() && isdigit(st.top())){
                    num=st.top()+num;
                    st.pop();
                }
                int number=stoi(num);
                while(number--){
                    for(int p = 0; p < str.size() ; p++)
                        st.push(str[p]);
                }
                

            }

        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};