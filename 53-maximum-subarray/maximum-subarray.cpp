class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = INT_MIN;
        int maxi = 0;
        for(int i =0;i<nums.size();i++){
            maxi += nums[i];
            max_so_far = max(maxi,max_so_far);
            maxi = max(0,maxi);
        }
        return max_so_far;
    }
};