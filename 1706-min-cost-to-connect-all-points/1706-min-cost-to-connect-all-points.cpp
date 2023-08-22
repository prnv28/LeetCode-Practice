class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int visited[V];
        for(int i=0;i<V;i++) visited[i] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        int total = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            int destination = it.second;
            int weight = it.first;
            
            pq.pop();
            
            if(visited[destination]==0){
                total +=weight;
                visited[destination] = 1;
                for(vector<int> adjNodes : adj[destination]){
                    if(visited[adjNodes[0]]==0) pq.push({adjNodes[1],adjNodes[0]});
                }
            }
        }
        return total;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> adj[n];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int distance = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,distance});
                adj[j].push_back({i,distance});
            }
        }

        return spanningTree(n,adj);

    }
};