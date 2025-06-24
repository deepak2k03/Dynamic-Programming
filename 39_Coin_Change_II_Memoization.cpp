class Solution {
public:
    int f(int i,int s, vector<int>&v,vector<vector<int>>&dp){
        if(i==0) return s%v[i]==0;
        if(dp[i][s]!=-1) return dp[i][s];
        int notTake=f(i-1,s,v,dp);
        int take=0;
        if(v[i]<=s) take=f(i,s-v[i],v,dp);
        return dp[i][s]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int x=f(coins.size()-1,amount,coins,dp);
        return x;
    }
};
