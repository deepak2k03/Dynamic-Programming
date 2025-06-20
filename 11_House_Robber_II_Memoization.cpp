class Solution {
public:
    int f(int start, int n,vector<int>&dp,vector<int>&nums){
        if(start>n) return 0;
        if(dp[start]!=-1) return dp[start];
        int steal=nums[start]+f(start+2,n,dp,nums);
        int skip=f(start+1,n,dp,nums);
        return dp[start]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n,-1),dp2(n,-1);
        int x=f(0,n-2,dp1,nums);
        int y=f(1,n-1,dp2,nums);
        return max(x,y);
    }
};
