//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        int V = mat.size();
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(mat[i][j]==-1) mat[i][j] = 1e9;
                if(i==j) mat[i][j]=0;
            }
        }
        // for(int i=0;i< v : mat){
        //     for(int i=0;i<v.size();i++){
        //         if(v[i]==-1){
        //             v[i] = 1e9;
        //         }
        //     }
        // }
        
        for(int k=0;k<V;k++){
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    mat[i][j] = min(mat[i][j],mat[i][k] + mat[k][j]);
                }
            }
        }
        
        // for(auto v : mat){
        //     for(int i=0;i<v.size();i++){
        //         if(v[i]==1e9){
        //             v[i] = -1;
        //         }
        //     }
        // }
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(mat[i][j]==1e9) mat[i][j] = -1;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends