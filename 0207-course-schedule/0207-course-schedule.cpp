class Solution {
public:
    bool detectCycle(int i,int parent,int vis[],int dfsVis[],vector<int> adj[]){
        vis[i] = 1;
        dfsVis[i] = 1;
        for(int adjacent : adj[i]){
            if(!vis[adjacent]){
                if(detectCycle(adjacent,i,vis,dfsVis,adj)) return true;
            }else if(dfsVis[adjacent]){
                return true;
            }
        }
        dfsVis[i]=0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        int vis[numCourses];
        int dfsVis[numCourses];
        memset(vis,0,sizeof vis);
        memset(dfsVis,0,sizeof dfsVis);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(detectCycle(i,-1,vis,dfsVis,adj)) return false;
            }
        }
        return true;
        
    }
};