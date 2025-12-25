class Solution {
public:
    int helper(vector<int>& nums,int low,int high){
        int randomPivot = low + rand() % (high - low + 1);
        swap(nums[low], nums[randomPivot]);//random pivot
        int pivot = nums[low];
        int i=low;
        int j=high;

        while(i<j){
            while(  i<=high && nums[i]<=pivot ){
                i++;
            }
            while(j>=low && nums[j]>pivot ){
                j--;
            }
            if(i<j)swap(nums[i],nums[j]);
        }
        swap(nums[low],nums[j]);
        int partitionIndex=j;
        return partitionIndex;

    }
    void quickSort(vector<int>&nums,int low,int high){
        if(low<high){
            int partitionIndex=helper(nums,low,high);
            quickSort(nums,low,partitionIndex-1);
            quickSort(nums,partitionIndex+1,high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        //QUICK sort
        quickSort(nums,0,n-1);
        return nums;
    }
};