class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
     set<int> ds;
     for(auto i : nums){
         if(ds.find(i)!=ds.end()) return true;
         ds.insert(i);
     }   
     return false;
    }
};