class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt=0;
        while(n>0){
            int state=0;
            if(n&1==1)state=1;
            n=n>>1;
            if(state && n&1==1)cnt++;
        }
        return (cnt==1);
    }
};