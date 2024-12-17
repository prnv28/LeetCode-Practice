class Solution {
public:
    void printV(vector<int>& nums){
        for(int i:nums){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    void sortColors(vector<int>& nums) {
       int low = 0;
       int mid = 0;
       int high = nums.size() - 1;

       while(mid<=high){
        // cout<<low<<":"<<mid<<":"<<high<<endl;
        // printV(nums);
        if(nums[mid]==0){
            swap(nums[mid++],nums[low++]);
        }else if(nums[mid]==1){
            mid++;
        }else if(nums[mid]==2){
            swap(nums[mid],nums[high--]);
        }
       }
    }
};