class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<nums.size()-2;i++){
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int low = i+1;
                int high = nums.size()-1;
                int sum = 0-nums[i];
                while(low<high){
                    if(sum == nums[low]+nums[high]){
                        result.push_back({nums[i],nums[low],nums[high]});
                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1]) high--; 
                        low++;
                        high--;
                    }else if(sum<nums[low]+nums[high]) {
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