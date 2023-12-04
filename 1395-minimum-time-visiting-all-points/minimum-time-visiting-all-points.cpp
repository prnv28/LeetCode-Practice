class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int time = 0;
        for(int i=1;i<n;i++){
            int x1 = points[i-1][0];
            int y1 = points[i-1][1];
            int x2 = points[i][0];
            int y2 = points[i][1];
            time += max(abs(y2-y1),abs(x2-x1));
        }   
        return time;
    }
};