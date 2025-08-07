class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int vote = 1;
        int majority = nums[0];
        for(int i=1;i<n;i++){
            if(majority==nums[i]){
                vote++;
            }else{
                vote--;
            }
            if(vote==0){
                vote=1;
                majority=nums[i];
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==majority){
                count++;
            }
            if(count>=n/2){
                return majority;
            }
        }
        return -1;
    }
};