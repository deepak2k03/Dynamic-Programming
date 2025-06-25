// User function Template for C++

class Solution {
  public:
    int f(int ind,vector<int>&val, vector<int>&wt, int w,vector<vector<int>>&dp){
        if(ind==0){
            if(wt[0]<=w) return (w/wt[0])*val[0];//max no of times u can steal it
            else return 0;
        }
        if(dp[ind][w]!=-1) return dp[ind][w];
        int nt=0+f(ind-1,val,wt,w,dp);
        int t=INT_MIN;
        if(wt[ind]<=w) t=val[ind]+f(ind,val,wt,w-wt[ind],dp);
        return dp[ind][w]=max(t,nt);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        // code here
        vector<vector<int>>dp(val.size(),vector<int>(W+1,-1));
        return f(val.size()-1,val,wt,W,dp);
        
    }
};
