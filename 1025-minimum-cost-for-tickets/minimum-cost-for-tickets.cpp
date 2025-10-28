class Solution {
public:
    int solve(int n,vector<int>&days,vector<int>&costs,int i,vector<int>&DP){
        //invalid
        if(i>=n)return 0;
        if(DP[i]!=-1)return DP[i];
        //3options
        //1 day ticket
        int opt1=costs[0]+solve(n,days,costs,i+1,DP);
        //7 day ticket
        int j=i;
        while(j<n && days[j]<days[i]+7){
            j++;
        }
        int opt2=costs[1]+solve(n,days,costs,j,DP);
        //30 day ticket
        j=i;
        while(j<n && days[j]<days[i]+30){
            j++;
        }
        int opt3=costs[2]+solve(n,days,costs,j,DP);
        return DP[i]= min(opt1,min(opt2,opt3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // costs [1day, 7day, 30day]
        int n=days.size();
        vector<int>DP(n,-1);
        int ans=solve(n,days,costs,0,DP);
        return ans;
    }
};