class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        vector<int> prefix(n,0);
        prefix[0] = nums[0];
        int total = nums[0];
        for(int i=1;i<n;i++){
            total += nums[i];
            prefix[i] = total;
        }

        for(int i=0;i<n;i++){
            if(i==0){
                ans[i] = (total-prefix[i]) - ((n-i-1)*nums[i]);
            }else{
                // ans[i] = (i*nums[i]) - (prefix[i-1]) + (total-prefix[i]) - ((n-i-1)*nums[i]);  
                ans[i] = ((2*i-n+1)* nums[i]) + total - (prefix[i-1]+prefix[i]);
            }
        }
        return ans;
    }
};