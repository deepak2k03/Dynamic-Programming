class Solution {
  public:
    int f(int n, vector<int>&dp,vector<int>&height){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int left=f(n-1,dp,height)+abs(height[n]-height[n-1]);
        int right=INT_MAX;
        if(n>1) right=f(n-2,dp,height)+abs(height[n]-height[n-2]);
        return dp[n]=min(left,right);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n+1,-1);
        return f(n-1,dp,height);
    }
};
