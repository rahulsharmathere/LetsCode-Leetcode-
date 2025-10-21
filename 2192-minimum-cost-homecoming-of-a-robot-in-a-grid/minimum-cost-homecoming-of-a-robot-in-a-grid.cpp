class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int n=rowCosts.size();//rows
        int m=colCosts.size();//cols
    
        int i=startPos[0];
        int j=startPos[1];

        int k=homePos[0];
        int l=homePos[1];

        int cost=0;

        if (i < k)
            for (int r = i + 1; r <= k; r++)
                cost += rowCosts[r];
        else
            for (int r = i - 1; r >= k; r--)
                cost += rowCosts[r];

        if (j < l)
            for (int c = j + 1; c <= l; c++)
                cost += colCosts[c];
        else
            for (int c = j - 1; c >= l; c--)
                cost += colCosts[c];

        return cost;

    }
};