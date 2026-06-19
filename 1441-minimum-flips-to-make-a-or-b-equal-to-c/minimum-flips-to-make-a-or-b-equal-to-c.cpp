class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=0;i<32;i++){
            if(c&1){
                if(!(a&1) && !(b&1))ans++;
            }else{
                if(a&1 && b&1)ans+=2;
                else if(a&1)ans++;
                else if(b&1)ans++;
            }
            c=c>>1;
            a=a>>1;
            b=b>>1;
        }
        return ans;
    }
};