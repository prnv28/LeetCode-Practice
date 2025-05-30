//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool detectDFSCycle(int src,vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack){
        if(!visited[src]){
            visited[src] = true;
            recStack[src] = true;
            for(int it : adj[src]){
                if(!visited[it] && detectDFSCycle(it,adj,visited,recStack)){
                    return true;
                }else if(recStack[it]){
                    return true;
                }
            }
        
            recStack[src] = false;
            return false;    
        }
        
        
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<bool> visited(V,false);
        vector<bool> recStack(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detectDFSCycle(i,adj,visited,recStack)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends