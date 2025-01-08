class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 1;
        int majority = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==majority){
                vote++;
            }else{
                vote--;
            }
            if(vote<=0){
                vote=1;
                majority = nums[i];
            }
        }
        return majority;
    }
};