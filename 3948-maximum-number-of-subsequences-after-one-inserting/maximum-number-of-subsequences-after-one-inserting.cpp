class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();

        vector<int> prefix_l(n + 1);
        vector<int> suffix_t(n + 1);

        // Count L before each gap
        long long l_cnt = 0;
        long long lc_cnt = 0;
        long long lct_cnt = 0;

        for (int i = 0; i < n; i++) {
            prefix_l[i] = l_cnt;

            if (s[i] == 'L') {
                l_cnt++;
            }
            else if (s[i] == 'C') {
                lc_cnt += l_cnt;
            }
            else if (s[i] == 'T') {
                lct_cnt += lc_cnt;
            }
        }

        // Last gap: all L's are before it
        prefix_l[n] = l_cnt;

        long long extra_T = lc_cnt;


        // Count T after each gap
        long long t_cnt = 0;
        long long ct_cnt = 0;
        lct_cnt = 0;

        for (int i = n - 1; i >= 0; i--) {
            suffix_t[i + 1] = t_cnt;

            if (s[i] == 'T') {
                t_cnt++;
            }
            else if (s[i] == 'C') {
                ct_cnt += t_cnt;
            }
            else if (s[i] == 'L') {
                lct_cnt += ct_cnt;
            }
        }

        // First gap: all T's are after it
        suffix_t[0] = t_cnt;

        long long extra_L = ct_cnt;


        // Adding C at any of the n+1 gaps
        long long extra_C = 0;

        for (int i = 0; i <= n; i++) {
            extra_C = max(extra_C,1LL * prefix_l[i] * suffix_t[i]);
        }

        return lct_cnt + max({extra_C, extra_L, extra_T});
    }
};