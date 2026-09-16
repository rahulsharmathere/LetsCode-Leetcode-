class Solution {
public:
    static bool comparator(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // interval (start,end)
        sort(intervals.begin(), intervals.end(),comparator);
        
        int freetime = INT_MIN;
        int cnt = 0;
        for(int i=0 ; i<n ; i++){
            if(intervals[i][0]>=freetime){
                freetime=intervals[i][1];
                cnt++;
            }
        }
        return intervals.size()-cnt;
    }
};