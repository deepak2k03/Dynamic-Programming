class Solution {
public:
    int f(int start,int n,vector<int>&nums){
        if(start==n) return nums[start];
        vector<int>dp(n-start+1,-1);
        dp[0]=nums[start];
        dp[1]=max(nums[start],nums[start+1]);
        for(int i=2;i<dp.size();i++){
            int steal=dp[i-2]+nums[i+start];
            int skip=dp[i-1];
            dp[i]=max(steal,skip);
        }
        return dp[dp.size()-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0]; 
        return max(f(0,n-2,nums),f(1,n-1,nums));
    }
};
