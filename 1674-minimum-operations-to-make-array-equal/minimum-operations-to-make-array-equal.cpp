class Solution {
public:
    int minOperations(int n) {
        int i = 0;
        int result = 0;
        while((2*i+1)<n){
            result+= (n-(2*i+1));
            i++;
        }
        return result;
    }
};