class Solution {
public:
    bool isPalindrome(int x) {
        long n = x;
        long num = 0;
        if(x<0) return false;
        while(n>0){
            int rem = n%10;
            num = num*10 + rem;
            n /=10;
        }
        return num==x?true:false;
    }
};