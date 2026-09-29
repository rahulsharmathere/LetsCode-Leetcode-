
class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> total(3, 0);
        for (char ch : s) {
            total[ch - 'a']++;
        }
        if (total[0] < k || total[1] < k || total[2] < k)
            return -1;
        int maxA = total[0] - k;
        int maxB = total[1] - k;
        int maxC = total[2] - k;
        vector<int> cnt(3, 0);
        int l = 0;
        int maxLen = 0;
        for (int r = 0; r < n; r++) {
            cnt[s[r] - 'a']++;
            while (cnt[0] > maxA || cnt[1] > maxB || cnt[2] > maxC) {
                cnt[s[l] - 'a']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return n - maxLen;
    }
};