class Solution {
public:
    void nextLargerElement(vector<int>& arr,unordered_map<int,int> &mp) {
        int n=arr.size();
        vector<int> result(n,-1);
        stack<int> s;
        s.push(arr[n-1]);
        mp[arr[n-1]] = -1;
        for(int i=n-2;i>=0;i--){
            if(!s.empty() && s.top()>arr[i]){
                result[i]=s.top();
            }else if(!s.empty() && s.top()<=arr[i]){
                while(!s.empty() && s.top()<=arr[i]){
                    s.pop();
                }
                if(!s.empty()){
                    result[i] = s.top();
                }
            }
            s.push(arr[i]);
            mp[arr[i]] = result[i];
        }
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        nextLargerElement(nums2,mp);
        
        int n = nums1.size();
        vector<int> result(n);
        for(int i=0;i<nums1.size();i++){
            result[i] = mp[nums1[i]];
        }
        
        return result;
    }
};