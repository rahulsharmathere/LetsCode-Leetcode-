class Solution {
public:
    bool haveConflict(vector<string>& e1, vector<string>& e2) {
        bool ans=false;
        if(e1[0]<=e2[1] && e2[0]<=e1[1])ans=true;
        return ans;
    }
};