class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        // count for every 1 -> no of zeroes group ahead
        int cnt=0;
        int ans=0;
        int prev=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                if(prev!=0)
                    cnt++;
                prev=0;
            }
            else{
                ans+=cnt;
                prev=1;
            }
            
        }
        return ans;  
    }
};