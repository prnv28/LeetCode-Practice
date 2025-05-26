class Solution {
public:
    
    void sumF(int ind,vector<int> &arr,set<vector<int>> &s, vector<int> &ds, vector<vector<int>> &result, int target){

        if(target==0 && s.find(ds)==s.end()){
            s.emplace(ds);
            result.push_back(ds);
        }
        if(ind == arr.size()) return;
        
        
        for(int i=ind;i<arr.size();i++){
            
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break; 
            ds.push_back(arr[i]);
            sumF(i+1,arr,s,ds,result,target-arr[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        set<vector<int>> s;
        sort(candidates.begin(),candidates.end());
        sumF(0,candidates,s,ds,result,target);
        return result;
    }
};