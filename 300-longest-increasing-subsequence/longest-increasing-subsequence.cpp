class Solution {
public:
    int algo(int ind,int prev_ind,vector<int>& nums,vector<vector<int>>& dp){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][prev_ind+1]!=-1){
            return dp[ind][prev_ind+1];
        }
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            return dp[ind][prev_ind+1] = max(1 + algo(ind+1,ind,nums,dp),algo(ind+1,prev_ind,nums,dp));
        }else{
            return dp[ind][prev_ind+1] = algo(ind+1,prev_ind,nums,dp);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<=n;j++){
                
            }
        }
        algo(0,-1,nums,dp);
        return dp[0][0];
    }
};