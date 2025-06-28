class Solution {
public:
    int f(int ind, int buy, int fee, vector<int> &prices, vector<vector<int>> &dp){
        if(ind==prices.size()) return 0;
        int op1=0,op2=0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            op1=-prices[ind]+f(ind+1,0,fee,prices,dp);
            op2=f(ind+1,1,fee,prices,dp);
        }
        else{
            op1=prices[ind]-fee+f(ind+1,1,fee,prices,dp);
            op2=f(ind+1,0,fee,prices,dp);
        }
        return dp[ind][buy]=max(op1,op2);
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return f(0,1,fee,prices,dp);
    }
};
