class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        vector<pair<int,pair<int,int>>>cnt(n);
        int lastp=0;
        int lastm=0;
        int lastg=0;
        for(int i=0;i<n;i++){
            int cntp=0;
            int cntm=0;
            int cntg=0;
            for(int j=0;j<garbage[i].size();j++){
                if(garbage[i][j]=='M')cntm++;
                else if(garbage[i][j]=='P')cntp++;
                else cntg++;
            }
            cnt[i]={cntm,{cntp,cntg}};
            if(cntm>0)lastm=i;
            if(cntp>0)lastp=i;
            if(cntg>0)lastg=i;
        }
        int timem=0;
        int timep=0;
        int timeg=0;
        timem+=cnt[0].first;
        timep+=cnt[0].second.first;
        timeg+=cnt[0].second.second;
        for(int i=1;i<n;i++){
            if(lastm>=i)timem+=travel[i-1];
            if(lastp>=i)timep+=travel[i-1];
            if(lastg>=i)timeg+=travel[i-1];
            timem+=cnt[i].first;
            timep+=cnt[i].second.first;
            timeg+=cnt[i].second.second;

        }
        return timem+timep+timeg;
    }
};