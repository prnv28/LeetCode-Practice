class Solution {
public:
    void printV(vector<int>& V){
        for(int v : V){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // printV(nums);
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                reverse(nums.begin()+i,nums.end());
                // printV(nums);
                for(int j=i;j<n;j++){
                    if(nums[j]>nums[i-1]){
                        swap(nums[j],nums[i-1]);
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(),nums.end());
        // printV(nums);
    }
};