class Solution {
public:
    vector<vector<int>> adjacencyList(int V,vector<vector<int>>& edges){
        vector<vector<int>> list(V);
        for(auto edg : edges){
            list[edg[1]].push_back(edg[0]);
        }
        return list;
    }

    bool detectDFSCycle(int src,vector<int>& vis, vector<int>& onStack, vector<vector<int>>& adj){
        vis[src] = 1;
        onStack[src]=1;
        for(int ch : adj[src]){
            if(!vis[ch] && detectDFSCycle(ch,vis,onStack,adj)){
                return true;
            }
            if(onStack[ch]){
                return true;
            }
        }
        onStack[src]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> list = adjacencyList(V,prerequisites);
        string mode = "BFS";
        mode = "DFS";
        
        if(mode=="BFS"){
            vector<int> inDegree(V,0);
            for(auto edges : list){
                for(int j : edges){
                    inDegree[j]++;
                }
            }

            queue<int> q;
            for(int i=0;i<inDegree.size();i++){
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
            int cnt = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                cnt++;
                for(int ch : list[node]){
                    inDegree[ch]--;
                    if(inDegree[ch]==0){
                        q.push(ch);
                    }
                }
            }

            return (V==cnt);
        }else{
            vector<int> vis(V,0);
            vector<int> onStack(V,0);
            for(int i=0;i<V;i++){
                if(!vis[i]){
                    if(detectDFSCycle(i,vis,onStack,list)){
                        return false;
                    }
                }
            }
            return true;
        }
        
    }
};