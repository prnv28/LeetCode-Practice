class Solution {
public:
    // long algo(int i,int amount,vector<int> &coins){
    //     if(amount<=0) return 0;
    //     if(i<0 && amount>0) return INT_MAX;

    //     if(coins[i]<=amount){
    //         return min(algo(i-1,amount,coins),algo(i-1,amount%coins[i],coins)+(amount/coins[i]));
    //     }else{
    //         return algo(i-1,amount,coins);
    //     }
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     int ans = (int)algo(n-1,amount,coins);
    //     return ans==INT_MAX?-1:ans;
    // }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() ;
       vector<int> dp(amount+1,0) ; 
       for (int j  = 0; j < amount +1 ; j++){
            dp[j] = (j == 0) ? 0 : INT_MAX - 1;
       }
        vector<int> curr = dp ; 
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < amount + 1; j++) {
                if (coins[i - 1] > j)
                    curr[j] = 0 + dp[j];
                else
                    curr[j] = min(0 + dp[j], 1+curr[j-coins[i-1]]);
            }
            dp = curr; 
        }
        return (dp[amount]==INT_MAX-1)?-1:dp[amount];
        
    }
};