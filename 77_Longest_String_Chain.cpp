class Solution {
public:
    bool check(string &s1, string &s2){
        if(s1.size()!=s2.size()+1) return false;
        int i=0,j=0;
        while(i<s1.size()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else i++;
        }
        return i==s1.size() && j==s2.size();
    }
    int longestStrChain(vector<string>& arr) {
        sort(arr.begin(),arr.end(),[](string &a,string &b){ return a.size()<b.size();});
        int n = arr.size();
        int maxi=1;
        vector<int> dp(n, 1);
        for (int i = 0; i <= n - 1; i++) {
            for (int j = 0; j <= i - 1; j++) {
                if (check(arr[i],arr[j]) && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                }
            }
            if (dp[i]>maxi ) {
                maxi = dp[i];
            }
        }
        return maxi;
    }
};
