class Solution {
public:

    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        //sapce optimization
        vector<vector<int>>ahead(2, vector<int>(k+1, 0));// hold,cap
        vector<vector<int>>curr(2, vector<int>(k+1, 0));// hold,cap
        
        for(int i=n-1;i>=0;i--){
            for(int hold=0;hold<2;hold++){
                for(int cap=0;cap<=k;cap++){
                    if(cap==0)continue;//imp
                    //try all combinations:
                    if(hold){
                        //sell
                        int sell=prices[i] + ahead[0][cap-1];//where you add the profit

                        //skip
                        int skip=ahead[1][cap];

                        curr[1][cap]= max(sell,skip);

                    }else{
                        //buy
                        int buy= -prices[i] + ahead[1][cap];
                        //skip
                        int skip=ahead[0][cap];

                        curr[0][cap]=  max(buy,skip);

                    }
                }

            }
            ahead=curr;
        }
        return ahead[0][k];


    }
};