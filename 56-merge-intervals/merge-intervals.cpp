class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;

        int start=intervals[0][0];
        int end=intervals[0][1];

        for(int i=1;i<n;i++){
            int first=intervals[i][0];
            int second=intervals[i][1];
            if(first<=end){
                end=max(end,second);
                continue;
            }else{
                ans.push_back({start,end});
                start=first;
                end=second;
            }

        }
        ans.push_back({start,end});
        return ans;
    }
};