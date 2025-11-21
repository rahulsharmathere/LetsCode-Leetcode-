class Solution {
public:
    static bool cmpt(vector<int>&i,vector<int>&j){
        if(i[1]==j[1])return i[0]>j[0];
        return i[1]<j[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),cmpt);

        vector<int>nums;
        int a=-1;
        int b=-1;
        for(int i=0;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];

            int hasA=(start<=a && a<=end);
            int hasB=(start<=b && b<=end);

            if(hasA && hasB)continue;

            else if(hasB){
                int x=end;
                nums.push_back(x);
                a=b;
                b=x;
            }
            else if(hasA){
                nums.push_back(end - 1);
                nums.push_back(end);

                b = end;
                a = end - 1;
            }
            else{
                nums.push_back(end - 1);
                nums.push_back(end);

                a = end - 1;
                b = end;
            }

        }
        return nums.size();

    }
};