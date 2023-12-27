class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<n-2;i++){
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int low=i+1;
                int high = n-1;
                int sum = 0-nums[i];
                while(low<high){
                    if(nums[low]+nums[high]==sum) {
                        result.push_back({nums[i],nums[low],nums[high]});
                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1]) high--;
                        low++;
                        high--;
                    }else if(nums[low]+nums[high]>sum){
                        high--;
                    }else{
                        low++;
                    } 
                }
            }
        }
        return result;
    }
};