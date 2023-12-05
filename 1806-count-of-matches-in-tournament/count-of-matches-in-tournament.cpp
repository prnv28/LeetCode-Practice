class Solution {
public:
    int numberOfMatches(int n) {
        int count = 0;
        while(n>1){
            if(n&1){
                count += ((n-1)>>1);
                n =  (n>>1) + 1;
            }else{
                count += (n>>1);
                n = n>>1;
            }
        }
        return count;
    }
};