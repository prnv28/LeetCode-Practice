class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 1;
        int winner = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==winner) vote++;
            else{
                vote--;
                if(vote==0){
                    vote = 1;
                    winner = nums[i];
                }
            }
        }

        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==winner){
                count++;
            }
        }
        return count>=nums.size()/2?winner:-1;
    }
};