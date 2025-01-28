class Solution {
public:
    void printVoV(vector<vector<int>> V){
        for(auto v : V){
            for(int i : v){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int>> dp(len1+1, vector<int> (len2 + 1 , 0));

        for(int i=0;i<len1;i++){
            for(int j=0;j<len2;j++){
                if(text1[i]==text2[j]){
                    dp[i+1][j+1] = 1 + dp[i][j]; 
                }else{
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        // printVoV(dp);
        return dp[len1][len2];
    }
};