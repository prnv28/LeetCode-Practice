class Solution {
    public: int algo(vector < int > & nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int first = nums[0];
        int second = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int temp = second;
            second = max(nums[i] + first, second);
            first = temp;
        }
        return second;
    }
    int rob(vector < int > & nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector < int > arr1;
        vector < int > arr2;
        arr1.push_back(nums[0]);
        for (int i = 1; i < n - 1; i++) {
            arr1.push_back(nums[i]);
            arr2.push_back(nums[i]);
        }
        arr2.push_back(nums[n - 1]);
        return max(algo(arr1), algo(arr2));
    }
};