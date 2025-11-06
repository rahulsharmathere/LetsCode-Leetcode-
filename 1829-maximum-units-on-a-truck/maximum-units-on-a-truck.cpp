class Solution {
public:
    static bool myfunction(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]
        int n=boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),myfunction);
        int ans=0;
        for(int i=0;i<n;i++){
            if(truckSize==0)break;
            if(boxTypes[i][0]<=truckSize){
                truckSize-=boxTypes[i][0];
                ans+=(boxTypes[i][0]*boxTypes[i][1]);
            }else {
                ans += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
        }
        return ans;

    }
};