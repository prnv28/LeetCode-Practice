class Solution {
public:
    int arrangeCoins(int n) {
        if(n<=1) return n;
        for(int i=0;i<=n;i++){
            if((long)((long)i*(long)(i+1))>(long)2*n){
                return i-1;
            }
        }
        return 0;
    }
};