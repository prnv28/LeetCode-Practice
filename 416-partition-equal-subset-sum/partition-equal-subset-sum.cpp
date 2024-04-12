class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto sum_nums=reduce(nums.begin(),nums.end());
        unordered_map<int,bool> memo;
        if((sum_nums&1))
            return false;
        bitset<20000> b;
        sum_nums>>=1;
        for(const auto &x:nums)
        {
            b=(b<<x)|b;
            b[x-1]=true;
        }
        
        return b[sum_nums-1];
    }
};