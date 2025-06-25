class Solution {
  public:
    int f(int ind,vector<int>&val, vector<int>&wt, int w,vector<vector<int>>&dp){
        if(ind==0){
            if(wt[0]<=w) return val[0];
            else return 0;
        }
        if(dp[ind][w]!=-1) return dp[ind][w];
        int nt=0+f(ind-1,val,wt,w,dp);
        int t=INT_MIN;
        if(wt[ind]<=w) t=val[ind]+f(ind-1,val,wt,w-wt[ind],dp);
        return dp[ind][w]=max(t,nt);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>>dp(val.size(),vector<int>(W+1,-1));
        return f(val.size()-1,val,wt,W,dp);
    }
};
