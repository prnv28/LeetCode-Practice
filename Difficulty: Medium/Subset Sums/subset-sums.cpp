class Solution {
  public:
    
    void algo(int i,vector<int>& arr, int sum, vector<int>& ans){
        if(i==arr.size()){
            ans.push_back(sum);
        } else{
            algo(i+1, arr, sum+arr[i], ans);
            algo(i+1,arr,sum,ans);
        }
        return;
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        algo(0,arr,0,ans);
        return ans;
    }
};