class Solution {
  public:
    int f(int ind,int s,vector<int>&a,vector<vector<int>>&dp){
        if(s==0) return 1;
        if(ind==0) return (a[ind]==s);
        if(dp[ind][s]!=-1) return dp[ind][s];
        int notPick=f(ind-1,s,a,dp);
        int pick=0;
        if(a[ind]<=s) pick=f(ind-1,s-a[ind],a,dp);
        return dp[ind][s]=pick+notPick;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<int>nz;
        int z=0;
        for(auto i:arr){
            if(i!=0) nz.push_back(i);
            else z++;
        }
        vector<vector<int>>dp(nz.size()+1,vector<int>(target+1,-1));
        return f(nz.size()-1,target,nz,dp)*pow(2,z);
    }
};
