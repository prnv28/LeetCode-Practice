class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = accumulate(nums.begin(),nums.end(),0);
        if(target%2 || n<2) return false;
        target = target/2;

        vector<int> prev(target+1,0);
        prev[0] = 1;
        if(nums[0]<=target)
            prev[nums[0]] = 1;
        
        for(int i=1;i<n;i++){
            vector<int> curr(target+1,0);
            curr[0] = 1;
            for(int j=1;j<target+1;j++){
                if(j>=nums[i]){
                    curr[j] = prev[j-nums[i]] || prev[j];
                }else{
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[target];
        
    }
};