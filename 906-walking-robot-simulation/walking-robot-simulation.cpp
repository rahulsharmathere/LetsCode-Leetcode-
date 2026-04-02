class Solution {
public:
    int robotSim(vector<int>& c, vector<vector<int>>& ob) {
        int n=c.size();
        int ans=0;
        int x=0;
        int y=0;
        map<pair<int,int>,int>mp;
        for(int i=0;i<ob.size();i++){
            mp[{ob[i][0],ob[i][1]}]=1;
        }
        int dir=0;// 0n 1e 2s 3w
        
        for(int i=0;i<n;i++){
            if(c[i]==-2){
                dir=(dir-1+4)%4;
                continue;
            }
            if(c[i]==-1){
                dir=(dir+1)%4;
                continue;
            }
            int steps=c[i];
            while(steps--){
                int nx=x;
                int ny=y;
                if(dir==0)ny++;
                else if(dir==1)nx++;
                else if(dir==2)ny--;
                else nx--;

                if(mp[{nx,ny}]==1)break;
                x=nx;
                y=ny;
                int dist=x*x+y*y;
                ans=max(ans,dist);

            }
        }

        return ans;
    }
};