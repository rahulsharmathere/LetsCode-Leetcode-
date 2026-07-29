class Solution {
public:
    int mySqrt(int x) {
        long long start=0;
        long long end=x;
        long long mid=start-(start-end)/2;
        long long ans=-1;
        while(start<=end){
            mid=start-(start-end)/2;
            if(mid*mid==x)return mid;
            else if(mid*mid < x){
                start=mid+1;
                ans=mid;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};