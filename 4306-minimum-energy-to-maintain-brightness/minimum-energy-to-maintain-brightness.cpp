class Solution {
public:
    long long minEnergy(int n, int b, vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        long long  totalTime = 0;
        int currStart = intervals[0][0];
        int currEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            int st = intervals[i][0];
            int end = intervals[i][1];
            if(st <= currEnd +1) {
                currEnd = max(currEnd, end);
            }
            else {
                totalTime += currEnd - currStart + 1;
                currStart = st;
                currEnd = end;
            }
        }
        totalTime += currEnd - currStart + 1;

        if(n<3){
            return totalTime;
        }
        
        int left=b%3;
        long long  on=b/3;
        if(left>0)on++;
        

        return totalTime*on;


    }
};