class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        stack<int>st;
        if(k==n)return nums;

        st.push(nums[0]);        
        for(int i=1;i<n;i++){
            while(!st.empty() && st.top()>nums[i] && st.size()-1+(n-i)>=k) {
                st.pop();
            }     
            if(st.size()<k)
                st.push(nums[i]);
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};