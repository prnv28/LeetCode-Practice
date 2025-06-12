class Solution {
public:
    bool isValidIndex(int i,int j,int m,int n){
        return (i>=0 && i<m && j>=0 && j<n);
    }
    void dfs(int i,int j,int m, int n,vector<vector<int>>& vis, vector<vector<char>>& grid){
        if(isValidIndex(i,j,m,n)==false){
            return;
        }
        if(grid[i][j]=='0'){
            vis[i][j]=1;
            return;
        }

        vis[i][j]=1;
        if(isValidIndex(i+1,j,m,n)){
            if(!vis[i+1][j]){
                dfs(i+1,j,m,n,vis,grid);
            }
        }
        if(isValidIndex(i-1,j,m,n)){
            if(!vis[i-1][j]){
                dfs(i-1,j,m,n,vis,grid);    
            }
        }
        if(isValidIndex(i,j+1,m,n)){
            if(!vis[i][j+1]){
                dfs(i,j+1,m,n,vis,grid);
            }
        }
        if(isValidIndex(i,j-1,m,n)){
            if(!vis[i][j-1]){
                dfs(i,j-1,m,n,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,m,n,vis,grid);
                }else{
                    vis[i][j]=1;
                }
            }
        }
        return cnt;
    }
};