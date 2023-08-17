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
        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        // for(int i=0;i<target+1)

        algo(n-1,target,nums,dp);
        return dp[n-1][target];
        
    }
};