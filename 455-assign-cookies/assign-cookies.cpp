class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size()-1;
        int j = s.size()-1;
        int count = 0;
        for(int i=n;i>=0;i--){
            if(j>=0 && s[j]>=g[i]){
                count++;
                j--;
                
            }
        }
        return count;
    }
};