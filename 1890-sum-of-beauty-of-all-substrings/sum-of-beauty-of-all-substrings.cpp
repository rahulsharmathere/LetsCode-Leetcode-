class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sumBeauty = 0;

        for (int i = 0; i < n; i++) {
            int freq[26] = {0};

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int max_freq = 0;
                int min_freq = INT_MAX;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        max_freq = max(max_freq, freq[k]);
                        min_freq = min(min_freq, freq[k]);
                    }
                }

                sumBeauty += (max_freq - min_freq);
            }
        }
        return sumBeauty;
    }
};
