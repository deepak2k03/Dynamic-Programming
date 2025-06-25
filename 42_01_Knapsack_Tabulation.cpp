class Solution {
  public:
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>>dp(val.size(),vector<int>(W+1,0));
        for(int w=0;w<=W;w++) if (wt[0] <= w) dp[0][w] = val[0];
        for(int i=1;i<val.size();i++){
            for(int j=0;j<=W;j++){
                int nt=dp[i-1][j];
                int t=INT_MIN;
                if(wt[i]<=j) t=val[i]+dp[i-1][j-wt[i]];
                dp[i][j]=max(t,nt);
            }
        }
        return dp[val.size()-1][W];
    }
};
