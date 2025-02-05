class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int first = 0;
        int last = (m*n) - 1;
        while(first<=last){
            int mid = (first+last)/2;
            int i = mid/n;
            int j = mid%n;
            if(matrix[i][j]<target){
                first = mid+1;
            }else if(matrix[i][j]>target){
                last = mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
};