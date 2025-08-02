class Solution {
public:
    void printV(vector<int>& V){
        for(int v : V){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return {};
        if(n==1) return {0};
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        vector<int> ans(n,0);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+nums[i];
            suffix[n-i-1] = suffix[n-i] + nums[n-i-1];
        }
        // printV(prefix);
        // printV(suffix);
        for(int i=0;i<n;i++){
            if(i==0){
                ans[i] = (suffix[i+1] - ((n-1-i)*nums[i]));
            }else if(i==n-1){
                ans[i] = (((i)*nums[i]) - prefix[i-1]);
            }else{
                ans[i] = (((i)*nums[i]) - prefix[i-1]) + (suffix[i+1] - ((n-i-1)*nums[i]));
            }
            
        }
        return ans;
    }
};