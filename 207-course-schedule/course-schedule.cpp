class Solution {
public:
    bool detectDFSCycle(int src,vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack){
        visited[src] = true;
        recStack[src] = true;

        for(int it : adj[src]){
            if(!visited[it] && detectDFSCycle(it,adj,visited,recStack)){
                    return true;
            }
            if(recStack[it]){
                return true;
            }
        }
        recStack[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        string mode = "DFS";
        // mode = "BFS";

        if(mode=="BFS"){
            queue<int> q;
            vector<int> indegree(numCourses,0);

            for(int i=0;i<numCourses;i++){
                for(int it : adj[i]){
                    indegree[it]++;
                }
            }

            for(int i=0;i<numCourses;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }
            int cnt = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                cnt++;
                for(int it : adj[node]){
                    indegree[it]--;
                    if(indegree[it]==0){
                        q.push(it);
                    }
                }
            }
            if(cnt==numCourses){
                return true;
            }else{
                return false;
            }
        }else{
            vector<bool> visited(numCourses,false), recStack(numCourses,false);

            for(int i=0;i<numCourses;i++){
                if(!visited[i]){
                    if(detectDFSCycle(i,adj,visited,recStack)){
                        return false;
                    }
                }
            }
            return true;
        }
    }
};