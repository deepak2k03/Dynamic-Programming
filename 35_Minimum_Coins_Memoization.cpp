class Solution {
public:
    int f(int i,int s, vector<int>&v,vector<vector<int>>&dp){
        if(i==0){
            if(s%v[i]==0) return s/v[i];
            else return INT_MAX;
        }
        if(dp[i][s]!=-1) return dp[i][s];
        int nt=f(i-1,s,v,dp);
        int t=INT_MAX;
        if(v[i]<=s){
            int sub=f(i,s-v[i],v,dp);
            if(sub!=INT_MAX) t=1+sub;
        }
        return dp[i][s]=min(t,nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int x=f(coins.size()-1,amount,coins,dp);
        return x==INT_MAX?-1:x;
    }
};
