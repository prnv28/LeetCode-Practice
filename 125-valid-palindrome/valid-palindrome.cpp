class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i=0,j=n-1;
        while(i<j){
            while(i<=n-1 && !iswalnum(tolower(s[i]))) i++;
            while(j>=0 && !iswalnum(tolower(s[j]))) j--;
            if(i>j) break;
            if(tolower(s[i])!=tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};