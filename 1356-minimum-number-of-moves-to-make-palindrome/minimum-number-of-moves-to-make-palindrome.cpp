class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        int ans=0;

        while(i<j){
            int k=j;
            while(k>i && s[k]!=s[i])k--;
            if(k==i){
                swap(s[i],s[i+1]);
                ans++;
            }else{
                while(k<j){
                    swap(s[k],s[k+1]);
                    ans++;
                    k++;
                }
                i++;
                j--;
            }
        }
        return ans;
    }
};