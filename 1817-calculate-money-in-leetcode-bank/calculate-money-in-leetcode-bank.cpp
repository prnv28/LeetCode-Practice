class Solution {
public:
    int totalMoney(int n) {
        int rem = n%7,weeks = n/7,total=0;
        for(int i=0;i<weeks;i++){
            total += (7*i)+28;
        }
        total += ((rem*(rem+1))/2) + (rem*weeks);
        return total;
    }
};