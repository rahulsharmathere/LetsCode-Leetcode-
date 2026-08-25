class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        long long mult=k;

        while(true){
            if(st.find(mult)==st.end()){
                return mult;
            }
            mult+=k;
        }
        
    }
};