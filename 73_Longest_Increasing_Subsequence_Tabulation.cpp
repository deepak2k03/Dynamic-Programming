class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n + 1,0));
        for(int idx=n-1;idx>=0;idx--){
            for(int prevIdx=idx-1;prevIdx>=-1;prevIdx--){
                int len=dp[idx+1][prevIdx+1];
                if(prevIdx==-1 || nums[idx]>nums[prevIdx]) len=max(len,1+dp[idx+1][idx+1]);
                dp[idx][prevIdx+1]=len;
            }
        }
        return dp[0][-1+1];
    }
};
