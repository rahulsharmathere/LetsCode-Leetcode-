class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        //first occ of each char
        vector<int>first(26,n-1);
        //last occ of each char
        vector<int>last(26,0);

        for(int i=0;i<n;i++){
            first[s[i]-'a']=min(first[s[i]-'a'],i);
            last[s[i]-'a']=max(last[s[i]-'a'],i);
        }

        int cnt=0;

        for(int i=0;i<26;i++){
            if(first[i]<last[i]){
                vector<bool>isPresent(26,0);
                for(int k=first[i]+1;k<last[i];k++){
                    isPresent[s[k]-'a']=1;
                }
                int unique=0;
                for(int k=0;k<26;k++){
                    if(isPresent[k]==1)unique++;
                }
                cnt+=unique;
            }
        }
        return cnt;
    }
};