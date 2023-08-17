class Solution {
public:
    bool algo(int i, int target, vector<int> &nums,vector<vector<int>>& dp){
        
        if(target==0) return 1;
        if(i==0){
            return nums[i]==target;
        }

        if(dp[i][target]!=-1) return dp[i][target];

        int notTaken = algo(i-1,target,nums,dp);
        int taken = 0;
        if(target>=nums[i]){
            taken = algo(i-1,target-nums[i],nums,dp);
        }

        return dp[i][target] = (notTaken || taken);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = accumulate(nums.begin(),nums.end(),0);
        if(target%2 || n<2) return false;
        target = target/2;
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<target+1;j++){
                if(j>=nums[i]){
                    dp[i][j] = dp[i-1][j-nums[i]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        }
        return dp[n-1][target];
        
    }
};