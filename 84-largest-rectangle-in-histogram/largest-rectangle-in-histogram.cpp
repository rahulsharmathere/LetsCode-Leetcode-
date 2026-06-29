class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        //max rectangle = h*((nse)-(pse)+1)
        stack<int>st;
        vector<int>pse(n,-1);
        vector<int>nse(n,-1);

        st.push(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=n && heights[st.top()] >= heights[i]){
                st.pop();
            }
            nse[i]=st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            pse[i]=st.top();
            st.push(i);
        }
        int maxAr=INT_MIN;
        for(int i=0;i<n;i++){
            int h=heights[i];
            int l=pse[i];
            int r=nse[i];
            int ar=h*(r-l-1);

            maxAr=max(maxAr,ar);
        }
        return maxAr;
    }
};