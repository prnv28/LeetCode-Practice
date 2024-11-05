class Solution {
public:
    bool isPalindrome(string s) {
        string cs = "";
        for(int i=0;i<s.size();i++){
            int c = int(s[i]);
            if(c>=65 && c<=90){
                cs += char(c+32);
            }else if((c>=48 && c<=57) || (c>=97 && c<=122)){
                cs += char(c);
            }
        }
        int n = cs.size();
        if(n>0){
            for(int i=0;i<=n/2;i++){
                if(cs[i]!=cs[n-i-1]) return false;
            }
        }
        return true;
    }
};