class Solution {
public:
    void printV(vector<int>& V){
        for(int v : V){
            cout<<v<<" ";
        }
        cout<<endl;
    } 
    int removeDuplicates(vector<int>& nums) {
        int low = 0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            // printV(nums);
            if(nums[i]>nums[low]){
                cout<<nums[low]<<" : "<<nums[i]<<endl;
                nums[++low] = nums[i];
            }
        }
        return low+1;
    }
};