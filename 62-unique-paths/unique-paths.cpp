class Solution {
public:
    int algo(int m,int n,vector<vector<int>> &dp){
        if(m<0 && n<0) return 0;

        if(dp[m][n]!=-1) return dp[m][n];

        if(m==0) return dp[m][n] = algo(m,n-1,dp);
        if(n==0) return dp[m][n] = algo(m-1,n,dp);
        return dp[m][n]  = algo(m-1,n,dp)+algo(m,n-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        dp[0][0] = 1;
        return algo(m-1,n-1,dp);
    }
};