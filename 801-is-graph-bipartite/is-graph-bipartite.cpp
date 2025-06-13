class Solution {
public:
    bool BFS(int src, vector<int>& color, vector<vector<int>>& list){
        queue<int> q;
        q.push(src);
        color[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int ch : list[node]){
                if(color[ch]==-1){
                    color[ch]=!color[node];
                    q.push(ch);
                }else if(color[ch]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }

    bool DFS(int src,int clr,vector<int>& color,vector<vector<int>>& list){
        color[src] = clr;
        for(int ch : list[src]){
            if(color[ch]==-1){
                if(!DFS(ch,!clr,color,list)){
                    return false;
                }
            }
            else if(color[ch]==color[src]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& list) {
        string mode = "BFS";
        mode = "DFS";
        int V = list.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(mode=="BFS"){
                    if(!BFS(i,color,list)){
                        return false;
                    }
                }else{
                    if(!DFS(i,0,color,list)){
                        return false;
                    }
                }
                
            }
        }
        return true;
    }

};