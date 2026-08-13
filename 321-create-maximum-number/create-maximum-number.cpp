class Solution {
public:
    vector<int> maxSubs(vector<int>&nums,int k){
        int n = nums.size();
        int drop = n - k;
        vector<int> st;
        for(int x : nums){
            while(!st.empty() && st.back() < x && drop){
                st.pop_back();
                drop--;
        }
        if(st.size() < k)
            st.push_back(x);
        else
            drop--;
        }
        return st;
    }
    vector<int> merge(vector<int>& A, vector<int>& B){
        vector<int> ans;
        int i = 0,j=0;
        while(i < A.size() || j < B.size()){

            if(greater(A,i,B,j))
                ans.push_back(A[i++]);
            else
                ans.push_back(B[j++]);
        }
        return ans;
    }
    bool greater(vector<int>& A, int i, vector<int>& B, int j){
        while(i < A.size() &&j < B.size() &&A[i] == B[j]){
            i++;
            j++;
        }
        return j == B.size() ||(i < A.size() && A[i] > B[j]);
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        int a = max(0,k-(int)nums2.size());
        int b = min(k,(int)nums1.size());
        for(int i = a;i<=b;i++){
            int j = k - i;
            vector<int> A = maxSubs(nums1,i);
            vector<int> B = maxSubs(nums2,j);
            vector<int> cur = merge(A,B);
            if(greater(cur,0,ans,0))
                ans=cur;
        }
        return ans;   
    }
};