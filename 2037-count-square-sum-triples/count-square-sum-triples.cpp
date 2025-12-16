class Solution {
public:
    int countTriples(int n) {
        vector<int>nums(n+1);
        for(int i=1;i<=n;i++){
            nums[i]=i*i;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                
                int s=i*i+j*j;
                int c=sqrt(s);
                if(c*c==s && c<=n)ans++;
            }
        }
        return ans*2;
    }
};