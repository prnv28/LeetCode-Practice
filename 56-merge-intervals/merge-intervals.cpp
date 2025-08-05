class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int> tmp = result.back();
            int tmps = tmp[0];
            int tmpe = tmp[1];
            int news = intervals[i][0];
            int newe = intervals[i][1];
            if(news<=tmpe){
                result.back()[1] = max(tmpe,newe);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};