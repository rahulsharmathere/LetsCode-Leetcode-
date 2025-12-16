class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size();
        map<int,long long>freq;
        for(int i=0;i<n;i++){
            freq[points[i][1]]++;
        }
        vector<long long>arr;
        for(auto it:freq){
            long long cnt=it.second;
            if(cnt>=2){
                arr.push_back((cnt*(cnt-1)/2));

            }
        }

        const int mod=1e9+7;
        long long ans=0;
        long long prefix=0;
        for(long long x:arr){
            ans=(ans+prefix*x) % mod;
            prefix=(prefix+x) % mod;
        }
        return ans;
    }
};