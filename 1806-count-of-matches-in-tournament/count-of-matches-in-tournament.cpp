class Solution {
public:
    int numberOfMatches(int n) {
        int count = 0;
        while(n>1){
            int temp = (n>>1);
            count += temp;
            if(n&1){
                n = temp+1;
            }else{
                n = temp;
            }
        }
        return count;
    }
};