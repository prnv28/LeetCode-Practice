class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int n = x;
        long long int sum = 0;
        while(n>0){
            sum = (sum*10)+(n%10);
            n /=10;
        }

        return (int)(sum)==x?true:false;
    }
};