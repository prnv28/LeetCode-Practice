//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    void dfs(int src, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st){
        visited[src] = true;
        for(int it : adj[src]){
            if(!visited[it]){
                dfs(it,adj,visited,st);
            }
        }
        st.push(src);
    }
    
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        string mode = "DFS";
        mode = "BFS";
        vector<int> result;
        int n = adj.size();
        if(mode=="DFS"){
            vector<bool> visited(n,false);
            stack<int> st;
            
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    dfs(i,adj,visited,st);
                }
            }
            
            while(!st.empty()){
                result.push_back(st.top());
                st.pop();
            }
        }else{
            vector<int> indegree(n,0);
            queue<int> q;
            
            for(int i=0;i<n;i++){
                for(int it : adj[i]){
                    indegree[it]++;
                }
            }
            
            for(int i=0;i<n;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                result.push_back(node);
                
                for(int it : adj[node]){
                    indegree[it]--;
                    if(indegree[it]==0){
                        q.push(it);
                    }
                }
            }
        }
        return result;
        
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends