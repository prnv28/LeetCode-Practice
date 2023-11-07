class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x!=0 && x%10==0)) return false;
        
        long long int n = x;
        long long int reversed = 0;
        while(n>0){
            reversed = (reversed*10)+(n%10);
            n /=10;
        }
        return (int)(reversed)==x;
    }
};