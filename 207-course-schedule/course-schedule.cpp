class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

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

    }
};