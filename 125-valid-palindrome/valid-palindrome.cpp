class Solution {
public:
    bool isPalindrome(string s) {
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