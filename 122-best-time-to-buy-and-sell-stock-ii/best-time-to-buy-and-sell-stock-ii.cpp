class Solution {
public:
    ////////////
    
    ////////////
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<int>ahead(2,0),curr(2,0);
        int aheadNotbuy;
        int aheadbuy;
        int currNotbuy;
        int currbuy;


        // ahead[0]=ahead[1]=0;
        aheadNotbuy=aheadbuy=0;

        for(int index=n-1;index>=0;index--){
            //copy recurrence
            //sell
            int sell=prices[index] + aheadbuy;//where you add the profit
            //skip
            int skip=aheadNotbuy;
            currNotbuy =  max(sell,skip);

            //buy
            int buy= -prices[index] +   aheadNotbuy;
            //skip
            skip=aheadbuy;
            currbuy=  max(buy,skip);

            aheadbuy=currbuy;
            aheadNotbuy=currNotbuy;
        }
        return aheadbuy;
    }
};