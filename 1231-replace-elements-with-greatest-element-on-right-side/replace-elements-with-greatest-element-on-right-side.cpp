class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<int> s;
        int n=arr.size();
        vector<int> result;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                result.push_back(-1);
                s.push(arr[i]);
            }else{
                result.push_back(s.top());
                if(s.top()<arr[i]){
                    s.pop();
                    s.push(arr[i]);
                }
            }
            
        }
        reverse(result.begin(),result.end());
        return result;
    }
};