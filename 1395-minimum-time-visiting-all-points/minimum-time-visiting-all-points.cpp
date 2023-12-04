class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int time = 0;
        vector<int> cord(4,0);
        for(int i=1;i<n;i++){
            cord[0] = points[i-1][0];
            cord[1] = points[i-1][1];
            cord[2] = points[i][0];
            cord[3] = points[i][1];
            time += max(abs(cord[3]-cord[1]),abs(cord[0]-cord[2]));
        }   
        return time;
    }
};