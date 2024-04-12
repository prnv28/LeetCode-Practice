class Solution {
public:
    bool algo(int i,int sum,vector<int> &nums,vector<vector<int>> &dp){
        if(i<0) return false;
        if(i==0) return sum==nums[i];
        if(dp[i][sum]!=-1) return dp[i][sum];
        int not_take = algo(i-1,sum,nums,dp);
        int take = false;
        if(sum>=nums[i]){
            take = algo(i-1,sum-nums[i],nums,dp);
        }
        return dp[i][sum] = take||not_take;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            total += nums[i];
        }
        if(total%2) return false;
        vector<vector<int>> dp(n,vector<int> ((total/2)+1,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<=total/2;j++){
                if(i==0){
                    dp[i][j] = (j==nums[i]);
                }else{
                    int not_take = dp[i-1][j];
                    int take = false;
                    if(j>=nums[i]){
                        take = dp[i-1][j-nums[i]];
                    }
                    dp[i][j] = take || not_take;
                }
            }
        }
        return dp[n-1][total/2];
        // return algo(n-1,total/2,nums,dp);
    }
};