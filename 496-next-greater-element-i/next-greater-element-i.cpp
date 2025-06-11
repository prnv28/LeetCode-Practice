class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return {-1};
        vector<int> result(n,-1);
        stack<int> s;
        s.push(arr[n-1]);
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
            
        }
        return result;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result2 = nextLargerElement(nums2);
        unordered_map<int,int> mp;

        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]] = i;
        }
        int n = nums1.size();
        vector<int> result(n);
        for(int i=0;i<nums1.size();i++){
            int index = mp[nums1[i]];
            result[i] = result2[index];
        }
        
        return result;
    }
};