class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        // leave minimum card sum (n-k) cards
        k=n-k;
        //find minimum window
        int total=0;
        for(auto it:cardPoints)total+=it;
        int sum=0;
        for(int r=0;r<k;r++){
            sum+=cardPoints[r];
        }
        int l=0;
        int r=k;
        int miniSum=sum;
        while(r<n){
            sum=sum-cardPoints[l]+cardPoints[r];
            miniSum=min(miniSum,sum);
            r++;
            l++;
        }
        return total-miniSum;
    }
};