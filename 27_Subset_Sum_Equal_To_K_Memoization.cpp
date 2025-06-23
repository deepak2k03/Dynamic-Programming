class Solution {
  public:
    bool f(int idx, int sum, vector<int>&arr,vector<vector<int>>&dp){
        if(sum==0) return true;
        if(idx==0) return arr[0]==sum;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool notTake=f(idx-1,sum,arr,dp);
        bool take=false;
        if(arr[idx]<=sum){
            take=f(idx-1,sum-arr[idx],arr,dp);
        }
        return dp[idx][sum]=take||notTake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
        return f(arr.size()-1,sum,arr,dp);
        
    }
};
