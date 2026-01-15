class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int n1=hBars.size();
        int n2=vBars.size();

        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int maxi=1;
        int cnt=1;
        for(int i=1;i<n1;i++){
            if(hBars[i]==hBars[i-1]+1){
                cnt++;
            }else{
                cnt=1;
            }
            maxi=max(maxi,cnt);
        }

        int maxii=1;
        int cnt2=1; 
        for(int i=1;i<n2;i++){
            if(vBars[i]==vBars[i-1]+1){
                cnt2++; 
            }else{
                cnt2=1;
            }
            maxii=max(maxii,cnt2);
        }
        maxi++;
        maxii++;
        int ans=min(maxi,maxii);
        return (ans*ans);
    }
};