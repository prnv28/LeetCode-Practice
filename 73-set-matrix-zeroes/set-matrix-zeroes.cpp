class Solution {
 public:
  
  void printm(vector<vector<int>>& m){
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
  }
  void setZeroes(vector<vector<int>>& matrix) {
    bool row = false;
    bool column = false;
    if(matrix[0][0]==0){
        row = true;
        column = true;
    }else{
         for (int i = 1; i < matrix.size(); i++) {
      if (matrix[i][0] == 0) {
        column = true;
        matrix[0][0] = 0;
      }
    }
    for (int j = 1; j < matrix[0].size(); j++) {
      if (matrix[0][j] == 0) {
        row = true;
        matrix[0][0] = 0;
      }
    }
    }
    // printm(matrix);
   
    // printm(matrix);
    for (int i = 1; i < matrix.size(); i++) {
      for (int j = 1; j < matrix[i].size(); j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    // printm(matrix);
    for (int i = 1; i < matrix.size(); i++) {
      if (matrix[i][0] == 0) {
        for (int j = 1; j < matrix[i].size(); j++) {
          matrix[i][j] = 0;
        }
      }
    }
    // printm(matrix);
    for (int j = 1; j < matrix[0].size(); j++) {
      if (matrix[0][j] == 0) {
        for (int i = 1; i < matrix.size(); i++) {
          matrix[i][j] = 0;
        }
      }
    }
    // printm(matrix);
    if (row) {
    //   cout<<"Row"<<endl;
      for (int j = 0; j < matrix[0].size(); j++) {
        matrix[0][j] = 0;
      }
    }
    // printm(matrix);
    if (column) {
    //   cout<<"column"<<endl;
      for (int i = 0; i < matrix.size(); i++) {
        matrix[i][0] = 0;
      }
    }
    // printm(matrix);
  }
};