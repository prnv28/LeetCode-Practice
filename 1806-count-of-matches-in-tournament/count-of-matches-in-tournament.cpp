class Solution {
public:
    int recur(int n){
        if(n<=1) return 0;
        if(n%2==0) return (n/2)+recur(n/2);
        else return ((n-1)/2)+recur(((n - 1) / 2) + 1);
    }
    int numberOfMatches(int n) {
        return recur(n);
    }
};