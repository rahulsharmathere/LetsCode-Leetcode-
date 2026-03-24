#define MOD 12345
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int total=n*m;
        vector<int>flatt(total);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                flatt[i*m+j]=grid[i][j];
            }
        }
        vector<int>pref(total);
        pref[0]=1;
        for(int i=1;i<total;i++){
            pref[i]=(1LL*pref[i-1]*flatt[i-1])%MOD;
        }
        vector<int>suff(total);
        suff[total-1]=1;
        for(int j=total-2;j>=0;j--){
            suff[j]=(1LL*suff[j+1]*flatt[j+1])%MOD;
        }

        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ind=i*m+j;
                ans[i][j]=(pref[ind]*suff[ind])%MOD;

            }
        }
        return ans;
    }
};