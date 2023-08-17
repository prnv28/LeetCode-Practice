class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        int n = coins.size();
        vector<int> curr = dp;

        for(int i=1;i<=n;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]>j){
                    curr[j] = 0 + dp[j];
                }else{
                    curr[j] = min(dp[j],1+curr[j-coins[i-1]]);
                }
            }
            dp = curr;
        }

        return dp[amount]==INT_MAX-1?-1:dp[amount];
    }
};