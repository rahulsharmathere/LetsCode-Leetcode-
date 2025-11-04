class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int n=hours.size();
        
        int start=0;
        int end=n-1;
        int index=n;
        sort(hours.begin(),hours.end());
        while(start<=end){
            int mid=start-(start-end)/2;
            if(hours[mid]>=target){
                index=mid;
                end=mid-1;
            }else {
                start=mid+1;
            }
        }
        
        return n-index;

    }
};