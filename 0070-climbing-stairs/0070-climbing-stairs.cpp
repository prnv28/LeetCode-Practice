class Solution {
public:
    int climbStairs(int n) {
        int previous1 = 1;
        int previous2 = 1;

        for(int i=2; i<n+1; i++){
            int current = previous1 + previous2;
            previous1 = previous2;
            previous2 = current;
        }

        return previous2;

    }
};