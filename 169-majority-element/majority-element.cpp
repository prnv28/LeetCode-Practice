class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int vote = 0;
        int majority;
        for(int i=0;i<nums.size();i++){
            if(vote<=0){
                vote=1;
                majority = nums[i];
            }else if(nums[i]==majority){
                vote++;
            }else{
                vote--;
            }
        }
        int cnt = 0;
        for(int num : nums){
            if(num==majority) cnt++;
        }
        return cnt>=nums.size()/2?majority:-1;
    }
};