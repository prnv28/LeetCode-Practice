class Solution {
public:
    void algo(int i, vector<int>& nums, vector<int> &ds,vector<vector<int>>& ans){
        ans.push_back(ds);
        for(int ind = i;ind<nums.size();ind++){
            if(ind!=i && nums[ind]==nums[ind-1]) continue;
            ds.push_back(nums[ind]);
            algo(ind+1,nums,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        algo(0,nums,ds,ans);
        return ans;
    }
};