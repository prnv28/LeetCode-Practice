class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        k = k%n;
        if(k==0) return;
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};