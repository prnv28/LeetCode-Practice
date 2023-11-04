class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
     unordered_map<int,int> ds;
     for(auto i : nums){
         if(ds.find(i)!=ds.end()) return true;
         ds[i]++;
     }   
     return false;
    }
};