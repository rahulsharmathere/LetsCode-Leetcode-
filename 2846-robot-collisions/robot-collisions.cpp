class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<tuple<int,int,char,int>> v; 
        
        for(int i=0;i<n;i++){
            v.push_back({positions[i], healths[i], directions[i], i});
        }
        
        sort(v.begin(), v.end()); 
        
        stack<int> st; 
        vector<int> finalHealth(n, -1);
        
        for(int i=0;i<n;i++){
            auto &[pos, h, dir, idx] = v[i];
            
            if(dir=='R'){
                st.push(i);
            }
            else{
                while(!st.empty() && h>0){
                    auto &[pos2, h2, dir2, idx2] = v[st.top()];
                    
                    if(h2 < h){
                        st.pop();
                        h--;
                    }
                    else if(h2 == h){
                        st.pop();
                        h = 0;
                        h2 = 0;
                        break;
                    }
                    else{
                        h2--;
                        h = 0;
                        break;
                    }
                }
                
                if(h > 0){
                    finalHealth[idx] = h;
                }
            }
        }
        
        while(!st.empty()){
            int i = st.top(); st.pop();
            auto &[pos, h, dir, idx] = v[i];
            if(h > 0){
                finalHealth[idx] = h;
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(finalHealth[i] != -1){
                ans.push_back(finalHealth[i]);
            }
        }
        
        return ans;
    }
};