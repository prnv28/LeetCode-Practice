class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_fat = INT_MIN;
        int max_lat = 0;
        for(int i=0;i<nums.size();i++){
            max_lat += nums[i];
            max_so_fat = max(max_so_fat,max_lat);
            max_lat = max(0,max_lat);
        }   
        return max_so_fat;
    }
};