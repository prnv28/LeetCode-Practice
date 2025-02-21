//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
    public:
    
    vector<int> size,rank,parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i] = 1;
        }
    }
    
    int findParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int par_u = findParent(u);
        int par_v = findParent(v);
        if(par_u==par_v) return;
        
        if(size[par_u]<size[par_v]){
            parent[par_u] = par_v;
            size[par_v]+=size[par_u];
        }else{
            parent[par_v] = par_u;
            size[par_u]+=size[par_v];
        }
    }
    
    void unionByRank(int u,int v){
        int par_u = findParent(u);
        int par_v = findParent(v);
        if(par_u==par_v) return;
        
        if(rank[par_u]<rank[par_v]){
            parent[par_u] = par_v;
        }else if(rank[par_v]<rank[par_u]){
            parent[par_v] = par_u;
        }else{
            parent[par_v] = par_u;
            rank[par_u]++;
        }
        
    }
};

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int prims(int V, vector<vector<int>> adj[]){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> visited(V,false);
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            int edw = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(visited[u]) continue;
            visited[u]=true;
            sum +=edw;
            for(auto it : adj[u]){
                int v = it[0];
                int wt = it[1];
                if(!visited[v]){
                    pq.push({wt,v});
                }
        
            }
        }
        return sum;
    }
    
    
    
    int krushkal(int V, vector<vector<int>> adj[]){
        DisjointSet ds(V);
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                edges.push_back({it[1],{i,it[0]}});
            }
        }
        sort(edges.begin(),edges.end());
        int sum = 0;
        for(auto it:edges){
            int u = it.second.first;
            int v = it.second.second;
            int wt = it.first;
            if(ds.findParent(u)!=ds.findParent(v)){
                sum+=wt;
                ds.unionBySize(u,v);
            }
        }
        return sum;
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        string mode = "prims";
        mode = "krushkal";
        
        if(mode=="prims"){
            return prims(V,adj);
        }else{
            return krushkal(V,adj);
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends