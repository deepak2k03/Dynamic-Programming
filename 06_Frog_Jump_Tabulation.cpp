class Solution {
  public:

    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(1e5,-1);
        dp[0]=0;
        int ss=INT_MAX;
        for(int i=1;i<n;i++){
            int fs=dp[i-1]+abs(height[i]-height[i-1]);
            if(i>1) ss=dp[i-2]+abs(height[i]-height[i-2]);
            dp[i]=min(fs,ss);
        }
        return dp[n-1];
    }
};
