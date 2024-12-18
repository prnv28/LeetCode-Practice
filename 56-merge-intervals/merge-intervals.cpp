class Solution {
public:
    void print(vector<vector<int>>& intervals){
        for(auto intvl : intervals){
            cout<<"["<<intvl[0]<<","<<intvl[1]<<"], ";
        }
        cout<<endl;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int> tmp = result.back();
            if(tmp[1]>=intervals[i][0]){
                result.pop_back();
                result.push_back({tmp[0],max(tmp[1],intervals[i][1])});
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};