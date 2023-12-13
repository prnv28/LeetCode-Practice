class Solution {
public:
    int totalMoney(int n) {
        int rem = n%7;
        int weeks = n/7;
        int total = 0;
        for(int i=7;i<7+weeks;i++){
            total += (i*(i+1))/2;
            total -= ((i-7)*(i-6))/2;
        }
        for(int i=weeks+1;i<=weeks+rem;i++){
            total+= i;
        }
        return total;
    }
};