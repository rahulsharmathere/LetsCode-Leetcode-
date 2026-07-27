class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;

        int sum=0;  
        int n=height.size();
        vector<int>rm(n);
        vector<int>lm(n);
        lm[0]=height[0];
        rm[n-1]=height[n-1];

        for(int i=n-2;i>=0;i--){
            rm[i]=max(rm[i+1],height[i]);
        }

        for(int i=1;i<n;i++){
            lm[i]=max(lm[i-1],height[i]);
        }

        for(int i=0;i<n;i++){
            if(rm[i]==0 || lm[i]==0)continue;
            int mini=min(rm[i],lm[i]);
            int add=mini-height[i];
            sum+=add;
        }
        return sum;


    }
};