class Solution {
public:
    double myPow(double x, int n) {
        long p = n>=0?(long)n:(-1*(long)n);
        if(p==0) return 1;
        double ans = 1.0;

        while(p>1){
            if(p%2==0){
                x = x*x;
                p /=2;
            }else{
                ans *= x;
                p--; 
            }
        }
        if(n<0){
            return 1.0/(ans*x);
        }else{
            return ans*x;
        }
        
    }
};