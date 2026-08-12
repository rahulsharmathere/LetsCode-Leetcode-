class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int i=0;
        int j=0;
        string ans="";
        while(i<n && j<m){
            if(word1[i]>word2[j]){
                ans+=word1[i];
                i++;
            }else if(word1[i]<word2[j]){
                ans+=word2[j];
                j++;
            }else{
                int i2=i;
                int j2=j;
                while(i2<n && j2<m && word1[i2]==word2[j2]){
                    i2++;
                    j2++;
                }
                if(word1[i2] > word2[j2]){
                    ans+=word1[i];
                    i++;
                }else{
                    ans+=word2[j];
                    j++;
                }
            }
        }
        while(i<n){
            ans+=word1[i];
            i++;
        }
            
        while(j<m){
            ans+=word2[j];
            j++;
        }

        return ans;
            
    }
};