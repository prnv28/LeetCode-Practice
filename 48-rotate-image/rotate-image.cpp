class Solution {
public:
    void printm(vector<vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
               cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void transpose(vector<vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix[i].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }

    void vertical_mirror_image(vector<vector<int>>& matrix){
        for(int j=0;j<matrix.size()/2;j++){
            swap(matrix[j],matrix[matrix.size()-j-1]);
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        vertical_mirror_image(matrix);
        transpose(matrix);
    }
};