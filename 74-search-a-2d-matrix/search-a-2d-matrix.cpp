class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        // n elements per row
        int low = 0;
        int high = m*n-1;
        while(low<=high){
            int mid = (low+high)/2;
            int row = mid/n;
            int column = mid%n;
            if(matrix[row][column]==target){
                return true;
            }else if(matrix[row][column]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
};