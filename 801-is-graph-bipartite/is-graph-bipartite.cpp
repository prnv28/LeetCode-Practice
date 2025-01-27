class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> clr(n,-1);
        for(int i=0;i<n;i++){
            if(clr[i]==-1){
                queue<int> q;
                q.push(i);
                clr[i] = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int it : graph[node]){
                        if(clr[it]==-1){
                            clr[it] = !clr[node];
                            q.push(it);
                        }else if(clr[it]==clr[node]){
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};