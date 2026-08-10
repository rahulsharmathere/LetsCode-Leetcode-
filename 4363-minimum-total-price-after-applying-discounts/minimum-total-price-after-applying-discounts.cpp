class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n=prices.size();
        int m=discounts.size();
        double ans=0;
        for(int i=0;i<n;i++){
            ans+=prices[i];
        }
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        int i=0;
        int j=0;
        double saved=0;
        while(i<n && j<m){
            double p=prices[i];
            double d=discounts[j];
            saved+=p*(d/100);
            i++;
            j++;
        }
        return ans-saved;

    }
};