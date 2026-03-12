class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l = 0;
        int r = 0;
        int falsec = 0;
        int truec = 0;
        int result = 0;
        int n = answerKey.size();
        while (r < n) {
            if (answerKey[r] == 'T')
                truec++;
            if (answerKey[r] == 'F')
                falsec++;
            while (truec > k && falsec > k) {
                if (answerKey[l] == 'T')
                    truec--;
                if (answerKey[l] == 'F')
                    falsec--;
                l++;
            }
            result = max(result, r - l + 1);
            r++;
        }
        return result;
    }
};