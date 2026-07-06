class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        int cover1=0;
        vector<int>check(n,0);
        for(int i=0;i<n;i++){
            cover1--;
            if(lights[i]!=0 || cover1>0)check[i]=1;
            if(lights[i]==0)continue;
            cover1=max(cover1,lights[i]+1);
        }
        int cover2=0;
        for(int j=n-1;j>=0;j--){
            cover2--;
            if(lights[j]!=0 || cover2>0)check[j]=1;
            if(lights[j]==0)continue;
            cover2=max(cover2,lights[j]+1);
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(check[i]==1)continue;
            cnt++;
            i+=2;
        }
        return cnt;
    }
};