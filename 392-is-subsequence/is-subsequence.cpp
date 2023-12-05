class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0,n=t.size();
        int i=0,m=s.size();
        while(i<m && j<n){
            while(j<n){
                if(s[i]==t[j++]){
                    break;
                } 
            }
            i++;
        }
        return (m==0) || ((i==m && j<=n) && (s[i-1]==t[j-1]))?true:false;
    }
};