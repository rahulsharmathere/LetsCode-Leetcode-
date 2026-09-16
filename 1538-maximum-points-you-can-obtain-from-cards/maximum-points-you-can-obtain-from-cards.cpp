class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        // We leave n-k cards in the middle.
        int windowSize = n - k;

        int total = 0;
        for (int x : cardPoints) {
            total += x;
        }

        // Sum of the first window of size n-k
        int sum = 0;
        for (int i = 0; i < windowSize; i++) {
            sum += cardPoints[i];
        }

        int miniSum = sum;

        int l = 0;

        // Slide the window
        for (int r = windowSize; r < n; r++) {
            sum += cardPoints[r];
            sum -= cardPoints[l];
            l++;

            miniSum = min(miniSum, sum);
        }

        return total - miniSum;
    }
};