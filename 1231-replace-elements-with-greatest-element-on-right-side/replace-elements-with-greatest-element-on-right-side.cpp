class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=arr.size();
        vector<int> result(n);
        int maxi = arr[n-1];
        result[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            result[i] = maxi;
            maxi = max(maxi,arr[i]); 
        }
        return result;
    }
};