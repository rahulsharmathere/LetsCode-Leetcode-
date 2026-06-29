class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int s=matrix.size();
        int m=matrix[0].size();
        vector<int>heights(m,0);
        int ans=0;
        for(int i=0;i<s;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }else heights[j]=0;
            }
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
            int maxAr=0;
            for(int i=0;i<n;i++){
                int h=heights[i];
                int l=pse[i];
                int r=nse[i];
                int ar=h*(r-l-1);

                maxAr=max(maxAr,ar);
            }
            ans=max(maxAr,ans);

        }

        return ans;
    }
};