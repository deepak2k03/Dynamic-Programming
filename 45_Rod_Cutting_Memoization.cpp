// User function Template for C++

class Solution {
  public:
    int f(int ind, int N, vector<int>&price,vector<vector<int>>&dp){
        if(ind==0) return N*price[0];
        if(dp[ind][N]!=-1) return dp[ind][N];
        int nt=f(ind-1,N,price,dp);
        int t=INT_MIN;
        int rodLength=ind+1;
        if(rodLength<=N) t=price[ind]+f(ind,N-rodLength,price,dp);
        return dp[ind][N]=max(t,nt);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(price.size()-1,price.size(),price,dp);
        
    }
};
