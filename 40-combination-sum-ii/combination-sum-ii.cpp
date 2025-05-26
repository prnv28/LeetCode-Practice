class Solution {
public:
    void algo(int i,int target,vector<int>& nums, vector<int>&ds, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int ind = i;ind<nums.size();ind++){
            if(i!=ind && nums[ind]==nums[ind-1]) continue;
            if(target>=nums[ind]){
                ds.push_back(nums[ind]);
                algo(ind+1,target-nums[ind],nums,ds,ans);
                ds.pop_back();
            }else{
                break;
            }
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        algo(0,target,nums,ds,ans);
        return ans;    
    }

};