// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        for(int i=0;i<=n;i++) dp[0][i]=i*price[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int nt=dp[i-1][j];
                int t=INT_MIN;
                int rodLength=i+1;
                if(rodLength<=j) t=price[i]+dp[i][j-rodLength];
                dp[i][j]=max(t,nt);
            }
        }
        return dp[price.size()-1][price.size()];
        
    }
};
