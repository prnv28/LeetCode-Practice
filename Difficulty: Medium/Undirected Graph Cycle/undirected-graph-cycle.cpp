//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        queue<pair<int,int>> q;
        int n = adj.size();
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            q.push({i,-1});
            while(!q.empty()){
                int parent = q.front().second;
                int node = q.front().first;
                q.pop();
                if(!visited[node]){
                    visited[node] = true;
                    for(int i=0;i<adj[node].size();i++){
                        int child = adj[node][i];
                        if(!visited[child]){
                            q.push({child,node});
                        }else if(child!=parent){
                            return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends