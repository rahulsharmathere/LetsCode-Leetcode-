class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        vector<int>vis(26,0);
        stack<char>st;
        for(int i=0;i<n;i++){
            char c=s[i];
            freq[c-'a']--;
            if(vis[c-'a']==1)continue;
            char t=st.top();
            while(!st.empty() && c<st.top() && freq[st.top()-'a']>0){
                vis[st.top()-'a']=0;
                st.pop();
            }
            st.push(c);
            vis[c-'a']=1;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};