class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=INT_MAX;
        }
        for(int ind=1;ind<coins.size();ind++){
            for(int t=0;t<=amount;t++){
                int nt=0+dp[ind-1][t];
                int take=INT_MAX;
                if(coins[ind]<=t && dp[ind][t-coins[ind]]!=INT_MAX) take=1+dp[ind][t-coins[ind]];
                dp[ind][t]=min(take,nt);
            }
        }
        int x=dp[coins.size()-1][amount];
        return x==INT_MAX?-1:x;

    }
};
