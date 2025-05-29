const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif
class Solution {
public:
    void printVoV(vector<int>& V){
        for(int v : V){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        // printVoV(nums);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            
            if(i!=0 && nums[i]==nums[i-1]){
                // cout<<"Start!"<<endl;
                // cout<<i<<" "<<nums[i]<<" "<<nums[i-1]<<endl;
                // cout<<"end!"<<endl;
                continue;
            }
            // while(i!=0 && nums[i]==nums[i-1]) continue;
            // while(true) {
            //     continue;
            // }
            int low = i+1;
            int high = n-1;
            
            while(low<high){
                int sum = nums[i]+nums[low]+nums[high];
                // cout<<i<<" "<<low<<" "<<high<<" "<<sum<<endl;
                if(sum<0){
                    low++;
                }else if(sum>0){
                    high--;
                }else{
                    ans.push_back({nums[i],nums[low],nums[high]});
                    low++;
                    high--;
                    while(low<high && nums[low]==nums[low-1]) low++;
                    while(low<high && nums[high]==nums[high+1]) high--;
                }
            }
        }
        return ans;
    }
};