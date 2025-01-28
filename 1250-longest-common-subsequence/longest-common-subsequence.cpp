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
        vector<int> cur(len2 + 1 , 0), prev(len2+1,0);
        // string s = "";
        for(int i=0;i<len1;i++){
            for(int j=0;j<len2;j++){
                if(text1[i]==text2[j]){
                    cur[j+1] = 1 + prev[j]; 
                    // s+=text1[i];
                }else{
                    cur[j+1] = max(prev[j+1],cur[j]);
                }
            }
            prev = cur;
        }
        return cur[len2];
    }
};