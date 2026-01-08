class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++){
            string s1="";
            string s2="";
            for(int j=0;j<words[i].size();j++){
                if(j%2==0)s1+=words[i][j];
                else s2+=words[i][j];
            }
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            string s=s1;
            s+=s2;
            words[i]=s;
        }
        sort(words.begin(),words.end());
        int cnt=1;
        for(int i=1;i<n;i++){
            if(words[i]==words[i-1])continue;
            else cnt++;
        }
        return cnt;
    }
};