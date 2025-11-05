class Solution {
public:
    bool isPossible(int x,vector<int>&dist,double hr){
        double time=0.0;
        int n=dist.size();
        for(int i=0;i<n;i++){
            double t=(double)dist[i]/x;

            if(i==n-1){
                time+=t;
            }else{
                time+=ceil(t);
            }
            if(time>hr)return false;
        }
        return (time<=hr);
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s=1;
        int e=1e7;
        int ans=-1;
        while(s<=e){
            int mid=s-(s-e)/2;
            if(isPossible(mid,dist,hour)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};