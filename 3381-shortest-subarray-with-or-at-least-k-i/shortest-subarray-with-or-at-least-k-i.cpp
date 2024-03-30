class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size();
        int min_len = INT_MAX;
        int temp = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                temp = (i==j)?nums[j]:(nums[j] | temp);
                if(temp>=k) min_len = min(min_len,j-i+1); 
            }
        }
        
        return min_len<=n?min_len:-1;
    }
};