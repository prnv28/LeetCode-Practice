class Solution {
public:
    bool valid(int i, int j, int m, int n){
        if(i>=0 && i<m && j>=0 && j<n){
            return true;
        }
        return false;
    }
    void bfs(int i,int j,int m,int n,vector<vector<char>>& grid, vector<vector<int>>& visited){
        if(grid[i][j]=='1' && !visited[i][j]){
            visited[i][j] = 1;
            if(j+1)
            if(valid(i,j+1,m,n)){
                bfs(i,j+1,m,n,grid,visited);
            }
            if(valid(i,j-1,m,n)){
                bfs(i,j-1,m,n,grid,visited);
            }
            if(valid(i+1,j,m,n)){
                bfs(i+1,j,m,n,grid,visited);
            }
            if(valid(i-1,j,m,n)){
                bfs(i-1,j,m,n,grid,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]){
                    if(grid[i][j]=='1'){
                        count++;
                        bfs(i,j,m,n,grid,visited);
                    }
                }
            }
        }
        return count;
    }
};