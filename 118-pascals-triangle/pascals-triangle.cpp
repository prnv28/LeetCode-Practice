class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> solution;
        solution.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                if(j==0){
                    temp.push_back(1);
                }else if(j>0 && j<i){
                    temp.push_back(solution[i-1][j-1] + solution[i-1][j]);
                }else{
                    temp.push_back(1);
                }
            }
            solution.push_back(temp);
            temp.clear();
        }
        return solution;
    }
};