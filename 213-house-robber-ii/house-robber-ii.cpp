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
        if(n==1) return nums[0];
        int last = nums.back();
        nums.pop_back();
        int left = algo(nums);
        nums.push_back(last);
        nums.erase(nums.begin());
        int right = algo(nums);
        return max(left,right);
    }
};