class Solution {
public:
    void algo(int i,vector<int>& nums, vector<int>&ds, vector<vector<int>>& ans){
        ans.push_back(ds);
        for(int ind = i;ind<nums.size();ind++){
            if(i!=ind && nums[ind]==nums[ind-1]) continue;
            ds.push_back(nums[ind]);
            algo(ind+1, nums,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        algo(0,nums,ds,ans);
        return ans;
    }
};