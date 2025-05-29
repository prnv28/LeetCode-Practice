class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_so_far = 0;
        int curr_max = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                curr_max++;
            }else{
                curr_max = 0;
            }
            max_so_far = max(max_so_far,curr_max);
        }
        return max_so_far;
    }
};