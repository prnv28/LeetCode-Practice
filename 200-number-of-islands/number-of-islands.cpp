class Solution {
public:
    bool valid(int i, int j, int m, int n){
        if(i>=0 && i<m && j>=0 && j<n){
            return true;
        }
        return false;
    }
    void dfs(int i,int j,int m,int n,vector<vector<char>>& grid, vector<vector<int>>& visited){
        if(grid[i][j]=='1' && !visited[i][j]){
            visited[i][j] = 1;
            if(valid(i,j+1,m,n)){
                dfs(i,j+1,m,n,grid,visited);
            }
            if(valid(i,j-1,m,n)){
                dfs(i,j-1,m,n,grid,visited);
            }
            if(valid(i+1,j,m,n)){
                dfs(i+1,j,m,n,grid,visited);
            }
            if(valid(i-1,j,m,n)){
                dfs(i-1,j,m,n,grid,visited);
            }
        }
    }
    void bfs(int i,int j,int m,int n,vector<vector<char>>& grid, vector<vector<int>>& visited){
        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()){
            int row = q.front().first;
            int column = q.front().second;
            q.pop();
            if(grid[row][column]=='1' && !visited[row][column]){
                visited[row][column] = 1;
                if(valid(row,column-1,m,n)){
                    q.push({row,column-1});
                }

                if(valid(row,column+1,m,n)){
                    q.push({row,column+1});
                }

                if(valid(row-1,column,m,n)){
                    q.push({row-1,column});
                }

                if(valid(row+1,column,m,n)){
                    q.push({row+1,column});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        string mode = "DFS";
        // mode = "BFS";
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    if(mode=="BFS"){
                        bfs(i,j,m,n,grid,visited);
                    }else{
                        dfs(i,j,m,n,grid,visited);
                    }
                    
                }
            }
        }
        return count;
    }
};