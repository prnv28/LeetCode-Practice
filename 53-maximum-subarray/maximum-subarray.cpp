class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = INT_MIN;
        int maxi = 0;
        for(int n : nums){
            maxi += n;
            max_so_far = max(max_so_far,maxi);
            maxi = max(0,maxi);
        }
        return max_so_far;
    }
};