class Solution {
public:
    int countPrimes(int n) {
        //sieve of eratosthesis
        if(n<=1)return 0;
        vector<int>mark(n+1,1);
        int cnt=0;
        mark[0]=0;//for 1
        mark[1]=0;//for 1
        for(int i=2;i<n;i++){
            if(mark[i]==1)cnt++;
            for(int j=i*2;j<n;j+=i){
                mark[j]=0;
            }
        }
        return cnt;
    }
};