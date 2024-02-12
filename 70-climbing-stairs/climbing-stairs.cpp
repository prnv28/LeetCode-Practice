class Solution {
public:
    int climbStairs(int n) {
        int first = 1;
        int second = 2;
        if(n==1) return first;
        for(int i=2;i<n;i++){
            int count = first + second;
            first = second;
            second = count;
        }
        return second;
    }
};