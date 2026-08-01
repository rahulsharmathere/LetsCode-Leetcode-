class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(k==n)return "0";
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        num="";
        
        while(!st.empty()){
            num+=st.top();
            st.pop();
        }
        reverse(num.begin(),num.end());

        int i=0;
        while(i<num.size() && num[i]=='0')i++;
        num=num.substr(i); 

        return num.empty() ? "0" :num;

    }
};