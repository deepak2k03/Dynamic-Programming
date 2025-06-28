class Solution {
public:
    int f(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(ind==prices.size() || cap==0) return 0;
        int op1=0,op2=0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            op1=-prices[ind]+f(ind+1,0,cap,prices,dp);
            op2=f(ind+1,1,cap,prices,dp);
        }
        else{
            op1=prices[ind]+f(ind+1,1,cap-1,prices,dp);
            op2=f(ind+1,0,cap,prices,dp);
        }
        return dp[ind][buy][cap]=max(op1,op2);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,dp);
    }
};
