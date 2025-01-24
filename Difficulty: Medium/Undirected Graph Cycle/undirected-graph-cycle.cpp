//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectBFSCycle(int i,int parent, vector<vector<int>>& adj,vector<bool>& visited){
        visited[i] = true;
        
        for(int node : adj[i]){
            if(!visited[node]){
                if(detectBFSCycle(node,i,adj,visited)){
                    return true;
                }
            }else if(node!=parent){
                return true;
            }
        }
        return false;
    }
    // bool isCycle(vector<vector<int>>& adj) {
    //     int n = adj.size();
    //     vector<bool> visited(n,false);
        
    //     for(int i=0;i<n;i++){
    //         if(!visited[i]){
    //             if(detectBFSCycle(i,-1,adj,visited)){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
        
    // }
    bool detectDFSCycle(int src, int parent,vector<vector<int>>& adj, vector<bool>& visited){
        visited[src] = true;
        for(int i: adj[src]){
            if(!visited[i]){
                if(detectDFSCycle(i,src,adj,visited)){
                    return true;
                }
            }else if(parent!=i){
                return true;
            }
            
            
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(detectDFSCycle(i,-1,adj,visited)){
                    return true;
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