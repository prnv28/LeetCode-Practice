class Solution {
public:
    int uniquePaths(int m, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> curr(n);
        vector<int> prev(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    curr[j] = 1;
                }else{
                    curr[j] = prev[j] + curr[j-1];
                }
            }
            prev = curr;
        }
        return curr[n-1];
    }
};