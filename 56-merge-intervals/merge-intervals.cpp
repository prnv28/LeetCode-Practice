class Solution {
public:
    void print(vector<vector<int>>& intervals){
        for(auto intvl : intervals){
            cout<<"["<<intvl[0]<<","<<intvl[1]<<"], ";
        }
        cout<<endl;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(result.back()[1]>=intervals[i][0]){
                result.back()[1] = max(result.back()[1],intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};