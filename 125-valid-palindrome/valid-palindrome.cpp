class Solution {
public:
    bool isPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int i=0,j=s.size()-1;
        while(i<j){
            while(i < j && !iswalnum(tolower(s[i]))) i++;
            while(i < j && !iswalnum(tolower(s[j]))) j--;
            if(tolower(s[i])!=tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};