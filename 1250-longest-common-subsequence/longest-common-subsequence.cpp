class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        vector<int> cur(m+1,0);
        vector<int> prev(m+1,0);
        // string ans = "";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    cur[j] = 1+prev[j-1];
                    // ans += text1[i-1];
                }else{
                    cur[j] = max(prev[j],cur[j-1]);
                }
            }
            prev = cur;
        }
        // cout<<ans<<endl;
        return prev[m];
    }
};