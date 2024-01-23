class Solution {
public:
    int algo(int ind,vector<int>& dp,vector<int>& nums){
        if(ind==0) return dp[ind] = nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];

        return dp[ind] = max(nums[ind]+algo(ind-2,dp,nums),algo(ind-1,dp,nums));
    }
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size();
        vector<int> dp(n,-1);
        algo(n-1,dp,nums);
        return dp[n-1];
    }
};