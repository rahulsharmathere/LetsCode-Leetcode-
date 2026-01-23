class Solution {
public:
    int minimumPairRemoval(vector<int>& num) {
        int n=num.size();

        vector<long long> nums(n,0);
        for(int i=0;i<n;i++) nums[i]=num[i];

        vector<int> nxt(n),prev(n);

        for(int i=0;i<n;i++) nxt[i]=i+1;
        for(int i=0;i<n;i++) prev[i]=i-1;

        set<pair<long long,int>> ps;

        int bad=0;

        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) bad++;
            ps.insert({nums[i]+nums[i+1],i});
        }

        int ans=0;

        while(bad>0){
            auto it=ps.begin();
            int curr=it->second,ni=nxt[curr],p=prev[curr],nn=nxt[ni];

            ps.erase(it);
            if(nums[curr]>nums[ni]) bad--;

            if(p>=0){
                if(nums[p]>nums[curr]) bad--;
                if(nums[p]>nums[curr]+nums[ni]) bad++;
                ps.erase({nums[p]+nums[curr],p});
            }

            if(nn<n){
                if(nums[ni]>nums[nn]) bad--;
                if(nums[curr]+nums[ni]>nums[nn]) bad++;
                ps.erase({nums[ni]+nums[nn],ni});
            }

            nums[curr]=nums[curr]+nums[ni];
            nxt[curr]=nn;
            if(nn<n) prev[nn]=curr;
            if(p>=0) ps.insert({nums[p]+nums[curr],p});
            if(nn<n) ps.insert({nums[curr]+nums[nn],curr});

            ans++;
        }

        return ans;
    }
};