class Solution {

  public:
    int minDifference(vector<int>& nums) {
        // Your code goes here
        int n=nums.size();
        int sm=accumulate(begin(nums),end(nums),0);
        vector<vector<bool>>dp(n,vector<bool>(sm+1,false));
        for(int i=0;i<nums.size();i++) dp[i][0]=true;
        if(nums[0]<=sm) dp[0][nums[0]]=true;
        for(int idx=1;idx<n;idx++){
            for(int target=1;target<=sm;target++){
                bool notTake=dp[idx-1][target];
                bool take=false;
                if(nums[idx]<=target) take=dp[idx-1][target-nums[idx]];
                dp[idx][target]=take||notTake;
            }
        }
        int mn=1e9;
        for(int i=0;i<=sm/2;i++){
            if(dp[n-1][i]==true){
                int s1=i;
                int s2=sm-i;
                mn=min(mn,abs(s2-s1));
            }
        }
        return mn;
    }
};
