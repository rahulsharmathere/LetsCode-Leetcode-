class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n=price.size();
        //maximise the minimum differece bw to candies
        sort(price.begin(),price.end());
        int l=0;
        int r=1e9;
        int ans=l;
        while(l<=r){
            int mid=l-(l-r)/2;
            int cnt=1;
            int last=price[0];
            for(int i=1;i<n;i++){
                if(price[i]-last>=mid){
                    cnt++;
                    last=price[i];
                }
            }
            if(cnt>=k){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;

    }
};