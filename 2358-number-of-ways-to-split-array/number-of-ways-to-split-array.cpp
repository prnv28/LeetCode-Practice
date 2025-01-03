class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int waysToSplitArray(vector<int>& nums) {
        vector<long> prefixSum(nums.size(),0);
        long total = 0;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
            prefixSum[i] = total;
        }
        int count = 0;
        for(int i=0;i<prefixSum.size()-1;i++){
            if(2*prefixSum[i]>=total){
                count++;
            }
        }
        return count;
        
    }
};