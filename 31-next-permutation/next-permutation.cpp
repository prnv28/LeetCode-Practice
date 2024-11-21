class Solution {
public:
    void printV(vector<int>& v){
        for(int i : v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                reverse(nums.begin()+i+1,nums.end());
                for(int j=i+1;j<n;j++){
                    if(nums[j]>nums[i]){
                        swap(nums[i],nums[j]);
                        return;
                    }
                }
            }
        }
        
        reverse(nums.begin(),nums.end());
    
    }
};