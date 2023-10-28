class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(nums.size()==0) return 0;
        int maxsum = 0;
        int globalmax = INT_MIN;
        for(int n : nums){
            maxsum+= n;
            globalmax = max(globalmax,maxsum);
            if(maxsum<0){
                maxsum = 0;
            }
        }   
        return globalmax;
    }
};