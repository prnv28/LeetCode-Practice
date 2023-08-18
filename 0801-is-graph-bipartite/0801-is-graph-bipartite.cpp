class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        int color[v];
        for(int i=0;i<v;i++) color[i] = -1;
        
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