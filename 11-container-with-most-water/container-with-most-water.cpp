class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int ans=0;
        while(l<=r){
            int option=min(height[l],height[r])*(r-l);
            ans=max(ans,option);
            if(height[l]>height[r])r--;
            else l++;
        }
        return ans;
    }
};