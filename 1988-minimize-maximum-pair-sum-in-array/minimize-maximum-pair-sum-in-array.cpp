class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int minPairSum(vector<int>& nums) {
        int i=0,j=nums.size()-1,maxi=0;
        sort(nums.begin(),nums.end());
        while(i<j){
            maxi = max(maxi,nums[i++]+nums[j--]);
        }
        return maxi;
    }
};