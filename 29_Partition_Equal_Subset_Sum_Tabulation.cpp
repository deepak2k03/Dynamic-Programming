class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s=accumulate(begin(nums),end(nums),0);
        if(s&1) return false;
        s=s/2;
        int n=nums.size();
        vector<vector<bool>>dp(n+1,vector<bool>(s+1,false));
        for(int i=0;i<nums.size();i++) dp[i][0]=true;
        if(nums[0]<=s) dp[0][nums[0]]=true;
        for(int idx=1;idx<nums.size();idx++){
            for(int target=1;target<=s;target++){
                bool notTake=dp[idx-1][target];
                bool take=false;
                if(nums[idx]<=target) take=dp[idx-1][target-nums[idx]];
                dp[idx][target]=take||notTake;
            }
        }
        return dp[nums.size()-1][s];
    }
};
