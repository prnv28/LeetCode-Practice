class Solution {
public:
    int algo(int i,int j,vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0 && j==0) return dp[i][j] = 1;
        if(i<0) return 0;
        if(j<0) return 0;
        if(i==0) return dp[i][j] = algo(i,j-1,dp);
        if(j==0) return dp[i][j] = algo(i-1,j,dp);
        return dp[i][j] = algo(i,j-1,dp) + algo(i-1,j,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        cout<<dp[0][0]<<endl;
        return algo(m-1,n-1,dp);
    }
};