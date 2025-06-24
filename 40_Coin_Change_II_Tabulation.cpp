class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<unsigned long long>>dp(coins.size(),vector<unsigned long long>(amount+1,0));
        int n=coins.size();
        for(int i=0;i<=amount;i++) dp[0][i]=(i%coins[0]==0);
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                unsigned long long nt=dp[i-1][j];
                unsigned long long t=0;
                if(coins[i]<=j) t=dp[i][j-coins[i]];
                dp[i][j]=t+nt;
            }
        }
        return dp[n-1][amount];
    }
};
