class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(2*size);
        for(int i=0;i<size;i++){
            ans[i] = ans[size+i] = nums[i];
        }
        return ans;
    }
};