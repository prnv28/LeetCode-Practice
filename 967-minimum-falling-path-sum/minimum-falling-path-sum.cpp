class Solution {
public:

    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = 1e9;
        int n = matrix.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int l = j>0 ? matrix[i-1][j-1] : 1e9;
                int r = n-1>j ? matrix[i-1][j+1] : 1e9;
                matrix[i][j] += min(matrix[i-1][j],min(l,r));
            }
        }

        for(int i=0;i<n;i++) m = min(m,matrix[n-1][i]);
        return m;
    }
};