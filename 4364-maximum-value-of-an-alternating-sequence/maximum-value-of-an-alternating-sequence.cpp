class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1) return s;

        long long n1 = n / 2;
        long long ans1 = 1LL * s + n1 * m - (n1 ? n1 - 1 : 0);

        long long n2 = (n - 1) / 2;
        long long ans2 = 1LL * s + n2 * m - n2;

        return max(ans1, ans2);
    }
};