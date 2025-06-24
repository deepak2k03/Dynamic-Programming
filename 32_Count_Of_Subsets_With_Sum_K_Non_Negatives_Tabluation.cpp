class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<int>nz;
        int z=0;
        for(auto i:arr){
            if(i!=0) nz.push_back(i);
            else z++;
        }
        vector<vector<int>>dp(nz.size(),vector<int>(target+1,0));
        for(int i=0;i<nz.size();i++) dp[i][0]=1;
         int n = nz.size();
        if(n == 0) {
            return (target == 0) ? (1LL << z) : 0;
        }
        if(nz[0]<=target) dp[0][nz[0]]=1;
        
        for(int i=1;i<nz.size();i++){
            for(int j=0;j<=target;j++){
                int notPick=dp[i-1][j];
                int pick=0;
                if(nz[i]<=j) pick=dp[i-1][j-nz[i]];
                dp[i][j]=pick+notPick;
            }
        }
        return dp[nz.size()-1][target]*pow(2,z);
    }
};
