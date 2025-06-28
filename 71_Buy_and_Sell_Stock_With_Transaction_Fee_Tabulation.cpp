class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int op1=0,op2=0;
                if(j==1){
                    op1=-prices[i]+dp[i+1][0];
                    op2=dp[i+1][1];
                }
                else{
                    op1=prices[i]-fee+dp[i+1][1];
                    op2=dp[i+1][0];
                }
                dp[i][j]=max(op1,op2);
            }
        }
        return dp[0][1];
    }
};
