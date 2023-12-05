class Solution {
public:
    int numberOfMatches(int n) {
        return (n&~1)?(n-1):0;
    }
};