class Solution {
public:
    void algo(int i, vector<int>& nums, vector<int> ds, set<vector<int>>&res){
        if(i==nums.size()){
            sort(ds.begin(),ds.end());
            res.insert(ds);
            return;
        }
        ds.push_back(nums[i]);
        algo(i+1,nums,ds,res);
        ds.pop_back();
        algo(i+1,nums,ds,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> ds;
        algo(0,nums,ds,res);
        for(auto it : res){
            ans.push_back(it);
        }
        return ans;
    }
};