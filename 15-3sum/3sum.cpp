class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int sum = 0-nums[i];
                int low = i+1;
                int high = n-1;
                while(low<high){
                    if(nums[low]+nums[high]==sum){
                        result.push_back({nums[i],nums[low],nums[high]});
                        while(low<high && nums[low+1]==nums[low]) low++;
                        while(high>low && nums[high-1]==nums[high]) high--;
                        low++;
                        high--;
                    }else if(nums[low]+nums[high]<sum){
                        low++;
                    }else{
                        high--;
                    }
                }
            }
        }
        return result;
    }
};