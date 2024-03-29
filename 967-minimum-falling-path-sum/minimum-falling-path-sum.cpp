class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        int n = matrix.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int l = j>0 ? matrix[i-1][j-1] : 1e9;
                int r = n-1>j ? matrix[i-1][j+1] : 1e9;
                matrix[i][j] += min(matrix[i-1][j],min(l,r));
            }
        }

        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};