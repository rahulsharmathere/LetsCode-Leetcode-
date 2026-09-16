class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool solve(string &s, int index, int cnt) {
        if (cnt < 0) return false;

        if (index == n) {
            return cnt == 0;
        }

        if (dp[index][cnt] != -1) {
            return dp[index][cnt];
        }

        bool ans;

        if (s[index] == '(') {
            ans = solve(s, index + 1, cnt + 1);
        }
        else if (s[index] == ')') {
            ans = solve(s, index + 1, cnt - 1);
        }
        else {
            ans =
                solve(s, index + 1, cnt + 1) ||
                solve(s, index + 1, cnt - 1) ||
                solve(s, index + 1, cnt);
        }

        return dp[index][cnt] = ans;
    }

    bool checkValidString(string s) {
        n = s.size();

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(s, 0, 0);
    }
};