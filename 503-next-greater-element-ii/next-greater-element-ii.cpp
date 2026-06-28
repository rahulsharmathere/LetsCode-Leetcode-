class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>nge(n,-1);
        stack<int>st;
        st.push(-1);
        //monotonic stack
        for(int i=2*n;i>=0;i--){
            int val=nums[i%n];
            while(!st.empty() && val>=st.top()){
                st.pop();
            }
            if(i<n)st.empty()?nge[i]=-1:nge[i]=st.top();
            st.push(val);
        }
        return nge;
    }
};