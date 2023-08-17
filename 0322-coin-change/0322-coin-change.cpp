class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
        dp[0] = 0;
        sort(coins.begin(),coins.end());
        for(int i=1;i<amount+1;i++){
            dp[i] = amount+1;
            for(int c : coins){
                if((i-c)<0){
                    break;
                }else if(dp[i - c] != amount+1){
                    dp[i] = min(dp[i],1+dp[i-c]);
                }
            }
        }

        return dp[amount]==amount+1?-1:dp[amount];
    }
};