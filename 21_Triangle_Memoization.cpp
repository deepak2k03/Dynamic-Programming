class Solution {
public:
    int f(int i, int j, vector<vector<int>>&triangle, vector<vector<int>>&dp){
        int n=triangle.size();
        if(i==n-1) return triangle[n-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=triangle[i][j]+f(i+1,j,triangle,dp);
        int diag=triangle[i][j]+f(i+1,j+1,triangle,dp);
        return dp[i][j]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),-1));
        return f(0,0,triangle,dp);
    }
};
