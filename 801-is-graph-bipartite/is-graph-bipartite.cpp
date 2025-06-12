class Solution {
public:
    bool BFS(int src,vector<int>& vis, vector<int>& color, vector<vector<int>>& list){
        queue<int> q;
        q.push(src);
        color[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(!vis[node]){
                vis[node]=1;
                for(int ch : list[node]){
                    if(!vis[ch]){
                        color[ch]=!color[node];
                        q.push(ch);
                    }else if(color[ch]==color[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& list) {
        int V = list.size();
        vector<int> color(V,-1);
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(!BFS(i,vis,color,list)){
                    return false;
                }
            }
        }
        return true;
    }

};