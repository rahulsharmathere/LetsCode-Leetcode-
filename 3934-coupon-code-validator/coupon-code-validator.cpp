class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        vector<pair<int, string>> valid;
        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        for(int i = 0; i < code.size(); i++){
            string s = code[i];

            // f1: valid code
            bool f1 = !s.empty();
            for(char c : s){
                if(!isalnum(c) && c != '_'){
                    f1 = false;
                    break;
                }
            }

            // f2: valid business line
            bool f2 = (businessLine[i] == "electronics" ||
                       businessLine[i] == "grocery" ||
                       businessLine[i] == "pharmacy" ||
                       businessLine[i] == "restaurant");

            // f3: active
            bool f3 = isActive[i];

            if(f1 && f2 && f3)
                valid.push_back({priority[businessLine[i]],s});
        }

        // SORTING RULE
        sort(valid.begin(), valid.end(), [](auto &a, auto &b) {
            if (a.first != b.first)
                return a.first < b.first;   // businessLine order
            return a.second < b.second;     // lexicographical code
        });

        // extract result
        vector<string> ans;
        for (auto &p : valid)
            ans.push_back(p.second);
        return ans;
    }
};
