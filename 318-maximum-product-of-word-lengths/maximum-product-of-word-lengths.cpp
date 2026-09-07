class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxi = 0;

        for(int i = 0; i < words.size(); i++) {
            vector<int> check(26, 0);

            for(char c : words[i])
                check[c - 'a']++;

            for(int j = i + 1; j < words.size(); j++) {

                bool flag = true;

                for(char c : words[j]) {
                    if(check[c - 'a'] > 0) {
                        flag = false;
                        break;
                    }
                }

                if(flag) {
                    int pr = words[i].size() * words[j].size();
                    maxi = max(maxi, pr);
                }
            }
        }

        return maxi;
    }
};