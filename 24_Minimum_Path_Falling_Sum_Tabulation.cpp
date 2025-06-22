class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int mn=INT_MAX;
        for(int j=0;j<n;j++) dp[0][j]=matrix[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=10000,ld=10000,rd=10000;
                up=matrix[i][j]+dp[i-1][j];
                if(j-1>=0) ld=matrix[i][j]+dp[i-1][j-1];
                if(j+1<n) rd=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min(up,min(ld,rd));
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++) mini=min(mini,dp[n-1][j]);
        return mini;
    }
};
