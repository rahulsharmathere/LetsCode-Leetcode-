class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int g=0;//initially
        int idx=0;
        int totalg=0;
        int totalc=0;
        for(int i=0;i<n;i++){
            totalg+=gas[i];
            totalc+=cost[i];
        }
        if(totalg<totalc)return -1;
        for(int i=0;i<n;i++){
            g = g+gas[i]-cost[i];
            if(g<0){
                g=0;
                idx=i+1;
            }
        }
        return idx;
    }
};