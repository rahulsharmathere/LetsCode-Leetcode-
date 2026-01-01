class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> arr(n + m + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int pro = (num1[i] - '0') * (num2[j] - '0');
                arr[i + j] += pro;
            }
        }
        reverse(arr.begin(), arr.end());
        for (int i = n + m; i >= 1; i--) {
            arr[i - 1] += arr[i] / 10;
            arr[i] %= 10;
        }
        int zero = 0;
        while (zero <= n + m && arr[zero] == 0)
            zero++;
        if (zero == n + m + 1)
            return "0";
        string ans = "";
        for (int i = zero; i <= n + m; i++) {
            ans += to_string(arr[i]);
        }

        return ans;
    }
};