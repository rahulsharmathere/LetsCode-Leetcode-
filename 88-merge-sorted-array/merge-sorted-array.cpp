class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pt1=m-1;
        int pt2=0;
        while(pt1>=0 && pt2<n && nums1[pt1] > nums2[pt2]){
            swap(nums1[pt1],nums2[pt2]);
            pt1--;
            pt2++;
        }
        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.end());
        int j=0;
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[j];
            j++;
        }
    }
};
