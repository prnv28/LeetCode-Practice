class Solution {
public:
    void nextLargerElement(vector<int>& arr,unordered_map<int,int> &mp) {
        int n=arr.size();
        stack<int> s;
        s.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            if(!s.empty() && s.top()>arr[i]){
                if(mp.find(arr[i])!=mp.end()){
                    mp[arr[i]] = s.top();
                }
            }else if(!s.empty() && s.top()<=arr[i]){
                while(!s.empty() && s.top()<=arr[i]){
                    s.pop();
                }
                if(!s.empty()){
                    if(mp.find(arr[i])!=mp.end()){
                        mp[arr[i]] = s.top();
                    }
                }
            }
            s.push(arr[i]);
        }
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums1[i]]=-1;
        }
        nextLargerElement(nums2,mp);
        
        vector<int> result(n);
        for(int i=0;i<nums1.size();i++){
            result[i] = mp[nums1[i]];
        }
        
        return result;
    }
};