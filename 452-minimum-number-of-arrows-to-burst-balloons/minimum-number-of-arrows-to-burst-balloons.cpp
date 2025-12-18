class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        //count goups of overlapping intervals;
        sort(points.begin(),points.end(),[](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int cnt=1;
        long long last=points[0][1];
        for(int i=1;i<n;i++){
            
            if(last < points[i][0]){
                cnt++;
                last=points[i][1];
            }
        }
        return cnt;
    }
};