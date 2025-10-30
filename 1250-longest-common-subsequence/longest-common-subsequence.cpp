class Solution {
public:
  
    
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        vector<int>ahead(m+1,0);
        vector<int>curr(m+1,0);

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j])
                    curr[j]=1+ahead[j+1];
                else
                    curr[j]=max(ahead[j],curr[j+1]);
            }
            ahead=curr;
        }
        return ahead[0];
    }
};