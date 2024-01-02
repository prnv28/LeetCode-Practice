class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> ds;
        int maxi = 0;
        for(int num : nums){
            ds[num]++;
            maxi = max(ds[num],maxi);
        }
        vector<vector<int>> result(maxi);
        for(auto itr = ds.begin();itr!=ds.end();itr++){
            int n = itr->second;
            int i=0;
            while(n--){
                result[i++].push_back(itr->first);
            }
        }
        return result;
    }
};