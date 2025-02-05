class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int cnt = 1;
        int maxi = 1;
        int x = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==x+1){
                x++;
                cnt++;
            }else if(nums[i]==x){
                
            }else{
                x = nums[i];
                cnt = 1;
            }
            maxi = max(maxi,cnt);
        }   
        return maxi;
    }
};