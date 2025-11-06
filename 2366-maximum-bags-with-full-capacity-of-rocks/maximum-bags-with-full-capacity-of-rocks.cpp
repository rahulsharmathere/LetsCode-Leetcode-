class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        int addR=additionalRocks;
        vector<int>diff(n,0);
        for(int i=0;i<n;i++){
            diff[i]=capacity[i]-rocks[i];
        }
        sort(diff.begin(),diff.end());

        int ans=0;
        for(auto it:diff){
            if(it==0){
                ans++;
                continue;
            }
            if(addR>=it){
                addR-=it;
                ans++;
            }else{
                break;
            }
        }
        return ans;
    }
};