class Solution {
public:
    int f(int n, vector<int>&dp, vector<int>&nums){
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int steal= f(n-2,dp,nums)+nums[n];
        int skip=f(n-1,dp,nums);
        return dp[n]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return f(n-1,dp,nums);
    }
};
