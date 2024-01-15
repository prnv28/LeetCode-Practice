class Solution {
public:
    int lengthOfLastWord(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=s.size();
        int count = 0;
        int i=n-1;
        while(i>=0 and s[i]==' ') i--;
        for(;i>=0;i--){
            if(s[i]==' ') return count;
            count++;
        }
        return count;
    }
};