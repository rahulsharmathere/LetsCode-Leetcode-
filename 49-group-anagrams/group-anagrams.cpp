class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<pair<string, string>> v;
        for (int i = 0; i < n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            v.push_back({s, strs[i]});
        }
        sort(v.begin(), v.end());
        vector<vector<string>> ans;
        for (int i = 0; i < n; ) {
            vector<string> temp;
            temp.push_back(v[i].second);
            int j = i + 1;
            while (j < n && v[j].first == v[i].first) {
                temp.push_back(v[j].second);
                j++;
            }
            ans.push_back(temp);
            i = j;  
        }
        return ans;
    }
};
