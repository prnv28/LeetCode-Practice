class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> s;
        int n = nums2.size();
        for(int i=n-1;i>=0;i--){
            if(!s.empty() && s.top()>nums2[i]){
                mp[nums2[i]] = s.top();
            }else{
                while(!s.empty() && s.top()<=nums2[i]){
                    s.pop();
                }
                mp[nums2[i]] = s.empty()?-1:s.top();
            }
            s.push(nums2[i]);
        }
       
        n = nums1.size();
        vector<int> result(n,-1);
        for(int i=0;i<n;i++){
            result[i] = mp[nums1[i]];
        }
        return result;
        
    }
};