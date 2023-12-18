class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;
        int biggest = 0;
        int secondBiggest = 0;
        for(int i=0;i<n;i++){
            if(nums[i]>=biggest){
                secondBiggest = biggest;
                biggest = nums[i];
            }else if(nums[i]>secondBiggest){
                secondBiggest = nums[i];
            }

            if(nums[i]<=smallest){
                secondSmallest = smallest;
                smallest = nums[i];
            }else if(nums[i]<secondSmallest){
                secondSmallest = nums[i];
            }
        }
        return (secondBiggest*biggest) - (secondSmallest*smallest);
    }
};