class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for(int num : nums) target+=num;
        if((target & 1) || n<2) return false;
        target = target >> 1;

        int dp[target+1];
        for(int i=0;i<target+1;i++) dp[i]= 0;
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[target];
        
    }
};