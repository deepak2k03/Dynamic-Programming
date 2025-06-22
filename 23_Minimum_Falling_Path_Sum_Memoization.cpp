class Solution {
public:
    int f(int i,int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int n=matrix.size();
        if(j<0 || j>=n) return 10000;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=matrix[i][j]+f(i-1,j,matrix,dp);
        int ld=matrix[i][j]+f(i-1,j-1,matrix,dp);
        int rd=matrix[i][j]+f(i-1,j+1,matrix,dp);
        return dp[i][j]=min(up,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int mn=INT_MAX;
        for(int j=0;j<n;j++){
            int cur=f(n-1,j,matrix,dp);
            mn=min(mn,cur);
        }
        return mn;
    }
};
