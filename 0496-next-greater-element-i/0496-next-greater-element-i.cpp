class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> result(nums2.size(),-1);
        unordered_map<int,int> mp;
        for(int i = nums2.size()-1;i>=0;i--){
            if(s.empty()){
                s.push(nums2[i]);
            }else{
                while(!s.empty() && s.top()<=nums2[i]){
                    s.pop();
                }
                if(!s.empty() && s.top()>nums2[i]){
                    result[i] = s.top();
                }
                s.push(nums2[i]);
            }
            mp[nums2[i]] = result[i];
        }
        result.resize(0);
        result.reserve(nums1.size());
        for(int i=0;i<nums1.size();i++){
            result.push_back(mp[nums1[i]]);
        }
        return result;
        
    }
};