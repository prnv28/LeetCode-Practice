class Solution {
public:
    bool bfs(int src,vector<vector<int>>& graph, vector<int>& clr){
        queue<int> q;
        q.push(src);
        clr[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int it : graph[node]){
                if(clr[it]==-1){
                    clr[it] = !clr[node];
                    q.push(it);
                }else if(clr[it]==clr[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(int src,int color,vector<vector<int>>& graph, vector<int>& clr){
        if(clr[src]==-1){
            clr[src] = color;
            for(int it : graph[src]){
                if(clr[it]==-1){
                    if(!dfs(it,1-color,graph,clr)){
                        return false;
                    }
                }else if(clr[it]==color){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        string mode = "DFS";
        mode = "BFS";
        int n = graph.size();
        vector<int> clr(n,-1);
        for(int i=0;i<n;i++){
            if(clr[i]==-1){
                if(mode=="BFS"){
                    if(!bfs(i,graph,clr)){
                        return false;
                    }
                }else{
                    if(!dfs(i,0,graph,clr)){
                        return false;
                    }
                }
               
            }
        }
        
        return true;
    }
};