class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> data;
        data.reserve(n);
        data.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(data.back()<nums[i]){
                data.push_back(nums[i]);
            }else{
                data[lower_bound(data.begin(),data.end(),nums[i]) - data.begin()] = nums[i];
            }
        }
        return data.size();
    }
};