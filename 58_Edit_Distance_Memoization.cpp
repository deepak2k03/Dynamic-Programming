class Solution {
public:
    int minDistance(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        for(int j=0;j<=s2.size();j++) dp[0][j]=j;
        for(int i=0;i<=s1.size();i++) dp[i][0]=i;
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    int insert=dp[i][j-1];
                    int remove=dp[i-1][j];
                    int replace=dp[i-1][j-1];
                    dp[i][j]=1+min({insert,remove,replace});
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
