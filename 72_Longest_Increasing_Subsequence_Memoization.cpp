class Solution {
public:
    int f(vector<int> & nums, int idx, int prevIdx, vector<vector<int>> &dp){
        int n=nums.size();
        if(idx==n) return 0;
        if(dp[idx][prevIdx+1]!=-1) return dp[idx][prevIdx+1];
        int len=f(nums,idx+1,prevIdx,dp);
        if(prevIdx==-1 || nums[idx]>nums[prevIdx]) len=max(len,1+f(nums, idx+1, idx,dp));
        return dp[idx][prevIdx+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return f(nums, 0, -1, dp);
    }
};
