class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> cur(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=-1;j--){
                if(j==-1 || nums[i]>nums[j]){
                    cur[j+1] = max(1+cur[i+1],cur[j+1]);
                }
            }
        }
        return cur[0];
    }
};