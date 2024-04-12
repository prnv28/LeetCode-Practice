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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total%2) return false;
       
        vector<int> prev((total/2)+1,0);
        vector<int> curr((total/2)+1,0);
        for(int i=0;i<n;i++){
             
            for(int j=0;j<=total/2;j++){
                if(i==0){
                    curr[j] = (j==nums[i]);
                }else{
                    int not_take = prev[j];
                    int take = false;
                    if(j>=nums[i]){
                        take = prev[j-nums[i]];
                    }
                    curr[j] = take || not_take;
                }
            }
            prev = curr;
        }
        return prev[total/2];
    }
};