class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int first = 0;
        int last = (m*n) - 1;
        while(first<=last){
            int mid = (first+last)/2;
            if(matrix[mid/n][mid%n]<target){
                first = mid+1;
            }else if(matrix[mid/n][mid%n]>target){
                last = mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
};