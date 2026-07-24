class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n=strs.size();
        int zero=0;
        int one=0;
        vector<int>pref(s.size());
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')zero++;
            else one++;
            pref[i]=one;
        }        
        vector<bool>ans(n);
        for(int i=0;i<n;i++){
            int z=0;
            int o=0;
            int q=0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0')z++;
                else if(strs[i][j]=='1')o++;
                else q++;
            } 
            if(o>one || z>zero){
                ans[i]=false;
                continue;
            }
            int diff=one-o;
            for(int j=strs[i].size()-1;j>=0;j--){
                if(strs[i][j]!='?')continue;
                if(diff>0)strs[i][j]='1';
                else strs[i][j]='0';
                diff--;
            }
            int cntone=0;
            int marked=0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='1')cntone++;
                if(cntone>pref[j]){
                    ans[i]=false;
                    marked=1;
                    break;
                }
            }
            if(marked==0)
                ans[i]=true;

        }
        return ans;
        
    }
};