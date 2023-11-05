class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i==0){
                prefix[i] = nums[i];
                suffix[nums.size()-1-i] = nums[nums.size()-1-i];
            }else{
                prefix[i] = prefix[i-1]*nums[i];
                suffix[nums.size()-1-i] = suffix[nums.size()-i]*nums[nums.size()-1-i]; 
            }
           
        }
        vector<int> result(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i==0) result[i] = suffix[i+1];
            else if(i==nums.size()-1) result[i] = prefix[i-1];
            else result[i] = prefix[i-1]*suffix[i+1];
        }
        return result;
    }
};