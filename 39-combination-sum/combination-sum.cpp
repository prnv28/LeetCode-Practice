class Solution {
public:
    void algo(int ind, vector<int>& nums,vector<int> ds, vector<vector<int>>& ans,int target){
        if(ind==nums.size()){
            if(target==0){
                ans.push_back(ds);
                
            }
            return;
        }

        if(nums[ind]<=target){
            ds.push_back(nums[ind]);
            algo(ind,nums,ds,ans,target-nums[ind]);
            ds.pop_back();
        }
        algo(ind+1,nums,ds,ans,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        algo(0,nums,ds,ans,target);
        return ans;
    }
};