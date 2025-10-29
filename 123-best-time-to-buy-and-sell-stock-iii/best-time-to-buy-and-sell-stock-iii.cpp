class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));// index,hold,cap
        for(int hold=0;hold<2;hold++){
            for(int cap=0;cap<3;cap++){
                dp[n][hold][cap]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int hold=0;hold<2;hold++){
                dp[i][hold][0]=0;
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
                        int sell=prices[i] + dp[i+1][!hold][cap-1];//where you add the profit

                        //skip
                        int skip=dp[i+1][hold][cap];

                        dp[i][hold][cap]= max(sell,skip);

                    }else{
                        //buy
                        int buy= -prices[i] + dp[i+1][!hold][cap];
                        //skip
                        int skip=dp[i+1][hold][cap];

                        dp[i][hold][cap]=  max(buy,skip);

                    }
                }

            }
        }
        return dp[0][0][2];


    }
};