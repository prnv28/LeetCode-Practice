class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size();
        int arr[n];
        int min_len = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(j==i) arr[j] = nums[j];
                else arr[j] = nums[j] | arr[j-1];
                if(arr[j]>=k) min_len = min(min_len,j-i+1); 
            }
        }
        
        return min_len<=n?min_len:-1;
    }
};