class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0;
        int rightSum = 0;

        for(int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }

        int l = k-1;
        int r = n-1;
        int totalSum = leftSum;

        while(k--) {
            leftSum -= cardPoints[l];
            rightSum += cardPoints[r];
            l--;
            r--;

            totalSum = max(totalSum, leftSum + rightSum);
        }

        return totalSum;
    }
};