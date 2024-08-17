class Solution {
public:
    int reverse(int x) {
        long num = 0;
        long mul = 1;
        if(x<0){
            mul = -1;
            x = x*mul;
        } 
        while(x>0){
            int r = x%10;
            x /=10;
            num = num*10+r;
        }   
        return (mul*num)>INT_MAX || (mul*num)<INT_MIN?0:(int)(mul*num);
    }
};