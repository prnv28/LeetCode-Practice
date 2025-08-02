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
        vector<int> ans(n,0);
        prefix[0] = nums[0];
        int total = nums[0];
        for(int i=1;i<n;i++){
            total += nums[i];
            prefix[i] = prefix[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            if(i==0){
                ans[i] = (total - prefix[i] - ((n-1-i)*nums[i]));
            }else if(i==n-1){
                ans[i] = (((i)*nums[i]) - prefix[i-1]);
            }else{
                ans[i] = (((i)*nums[i]) - prefix[i-1]) + (total - prefix[i] - ((n-1-i)*nums[i]));
            }
            
        }
        return ans;
    }
};