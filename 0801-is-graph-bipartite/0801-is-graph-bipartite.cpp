class Solution {
public:

    bool dfs(int i,int col,vector<int>& color,vector<vector<int>> &graph){
        color[i] = col;

        for(int adj : graph[i]){
            if(color[adj]==-1){
                if(!dfs(adj,!col,color,graph)) return false;
            }else if(color[adj]==col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v,-1);
        queue<int> q;
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                color[i]=0;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int adj : graph[node]){
                        if(color[adj]==-1){
                            color[adj] = !color[node];
                            q.push(adj);
                        }else if(color[adj]==color[node]){
                            return false;
                        }
                    }
                } 
            }
        }
        return true;
    }
};