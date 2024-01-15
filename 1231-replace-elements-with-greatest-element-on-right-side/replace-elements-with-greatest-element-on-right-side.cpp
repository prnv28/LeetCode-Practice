class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int largest = -1;
        for (int i = arr.size()-1; i >= 0; i--) {
            swap(largest, arr[i]);
            largest = max(arr[i], largest);
        }
        return arr;
    }
};