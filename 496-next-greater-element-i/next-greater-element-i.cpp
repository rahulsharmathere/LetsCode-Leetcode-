class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>ans(n1,-1);
        unordered_map<int,int>mp;
        stack<int>st;
        st.push(nums2[n2-1]);
        mp[nums2[n2-1]]=-1;

        for(int i=n2-2;i>=0;i--){
            int el=nums2[i];
            while(!st.empty() && el>st.top()){
                st.pop();
            }
            mp[el]=st.empty()?-1:st.top();
            
            st.push(el);
        }
        for(int i=0;i<n1;i++){
            ans[i]=mp[nums1[i]];
        }
        return ans;
    }
};