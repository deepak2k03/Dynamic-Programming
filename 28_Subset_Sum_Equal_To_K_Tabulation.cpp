class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<bool>>dp(arr.size()+1,vector<bool>(sum+1,false));
        for(int i=0;i<arr.size();i++) dp[i][0]=true;
        dp[0][arr[0]]=true;
        for(int idx=1;idx<arr.size();idx++){
            for(int target=1;target<=sum;target++){
                bool notTake=dp[idx-1][target];
                bool take=false;
                if(arr[idx]<=target) take=dp[idx-1][target-arr[idx]];
                dp[idx][target]=take||notTake;
            }
        }
        return dp[arr.size()-1][sum];
        
    }
};
