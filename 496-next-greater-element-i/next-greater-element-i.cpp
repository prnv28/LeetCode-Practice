class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,pair<int,int>> mp;
        stack<int> s;
        int n = nums2.size();
        for(int i=n-1;i>=0;i--){
            if(!s.empty() && s.top()>nums2[i]){
                mp[nums2[i]] = {i,s.top()};
                s.push(nums2[i]);
            }else{
                while(!s.empty() && s.top()<=nums2[i]){
                    s.pop();
                }
                if(s.empty()){
                    mp[nums2[i]] = {i,-1};
                    s.push(nums2[i]);
                }else{
                    mp[nums2[i]] = {i,s.top()};
                    s.push(nums2[i]);
                }
            }
        }
        // for(auto it : mp){
        //     cout<<it.first<<" : "<<it.second.first<<" : "<<it.second.second<<endl; 
        //     // cout<<nums2[it.second.first]<<" : "<<it.second.second<<endl;
        // }
        n = nums1.size();
        vector<int> result(n,-1);
        for(int i=0;i<n;i++){
            result[i] = mp[nums1[i]].second;
        }
        return result;
        
    }
};