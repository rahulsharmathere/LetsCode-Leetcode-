class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //sapce optimization
        vector<vector<int>>ahead(2, vector<int>(3, 0));// hold,cap
        vector<vector<int>>curr(2, vector<int>(3, 0));// hold,cap
        
        for(int hold=0;hold<2;hold++){
            for(int cap=0;cap<3;cap++){
                ahead[hold][cap]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int hold=0;hold<2;hold++){
                ahead[hold][0]=0;
            }
        }
        // however these 2 base cases are already done in initialization but just for understanding

        for(int i=n-1;i>=0;i--){
            for(int hold=0;hold<2;hold++){
                for(int cap=0;cap<3;cap++){
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
        return ahead[0][2];


    }
};