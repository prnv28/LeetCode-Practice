class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i < n; i += 3) {
            vector<int> temp;
            for (int j = i; j < i + 3 && j < n; j++) {
                temp.push_back(nums[j]);
            }
            if (temp[temp.size()-1] - temp[0] > k){
                return {};
            }
            result.push_back(temp);
        }
        return result;
    }
};