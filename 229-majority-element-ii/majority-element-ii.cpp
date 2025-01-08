class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int cnt1=0, cnt2=0;
        int el1 = INT_MIN ,el2 = INT_MIN;

        for(int i=0;i<n;i++){
            if(cnt1==0 && el2!=nums[i]){
                cnt1 = 1;
                el1 = nums[i];
            }else if(cnt2==0 && nums[i]!=el1){
                cnt2 = 1;
                el2 = nums[i];
            }else if(nums[i]==el1){
                cnt1++;
            }else if(nums[i]==el2 && el1!=el2){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        int c1 = 0, c2 = 0;
        vector<int> result;
        for(int n : nums){
            if(n==el1) c1++;
            if(n==el2) c2++;
        }
        if(c1>n/3) result.push_back(el1);
        if(c2>n/3) result.push_back(el2);

        return result;
    }
};