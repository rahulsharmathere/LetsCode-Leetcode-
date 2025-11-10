class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=1e9;
        map<int,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            int v=nums[i];
            auto it=mp.find(v);
            if(it==mp.end()){
                mp[v]={i,-1};
            }
            else{
                int a=it->second.first;
                int b=it->second.second;
                if(b==-1){
                    it->second.second=i;
                }else{
                    ans=min(ans,2*(i-a));
                    it->second.first=b;
                    it->second.second=i;
                }
            }
        }
        if(ans==1e9)return -1;
        return ans;

    }
};