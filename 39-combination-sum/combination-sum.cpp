class Solution {
public:
    void algo(int ind, vector<int>& nums,vector<int> ds, vector<vector<int>>& ans,int target){
        if(target<0 || ind==nums.size()) return;
        if(target==0){
            ans.push_back(ds);
        }else{
            ds.push_back(nums[ind]);
            algo(ind,nums,ds,ans,target-nums[ind]);
            ds.pop_back();
            algo(ind+1,nums,ds,ans,target);
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        algo(0,nums,ds,ans,target);
        return ans;
    }
};