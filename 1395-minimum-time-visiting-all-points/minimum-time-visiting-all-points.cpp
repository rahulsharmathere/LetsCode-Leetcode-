class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int time=0;
        for(int i=1;i<n;i++){
            int x1=points[i-1][0];
            int y1=points[i-1][1];
            int x2=points[i][0];
            int y2=points[i][1];
            int diff1=abs(x1-x2);
            int diff2=abs(y1-y2);
            time+=min(diff1,diff2);
            time+=abs(diff1-diff2);

        }
        return time;
    }
};