class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n,0);
        vector<int> curr(n,0);
        int mini = INT_MAX;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                curr[j] = matrix[i][j];
                if(i==0){
                }else if(j==0){
                    curr[j] += min(prev[j],prev[j+1]);
                }else if(j==n-1){
                    curr[j] += min(prev[j-1],prev[j]);
                }else{
                    curr[j] += min(min(prev[j-1],prev[j]),prev[j+1]);
                }

                if(i==m-1){
                    mini = min(mini,curr[j]);
                }
            }
            prev = curr;
        }
        return mini;
    }
};