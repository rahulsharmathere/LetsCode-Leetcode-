class Solution {
public:
    int reverseBits(int n) {
        uint32_t res = 0;
        for(int i=0 ; i<32 ; i++){
            if(n&1){
                res=res|(1<<(31-i));
            }
            n=n>>1;
        }
        return res;
    }
};