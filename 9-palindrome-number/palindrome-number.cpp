class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        long num = 0;
        if(x<0) return false;
        while(n>0){
            num = num*10 + n%10;
            n /=10;
        }
        return num==x?true:false;
    }
};