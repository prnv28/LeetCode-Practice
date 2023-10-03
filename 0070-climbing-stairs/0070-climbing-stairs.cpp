class Solution {
public:
    int climbStairs(int n) {
        if(n==0){
            return 0;
        }else if(n==1){
            return 1;
        }else if(n==2){
            return 2;
        }
        int prev2 = 1;
        int prev = 2;
        int temp;
        for(int i=3;i<n;i++){
            temp = prev + prev2;
            prev2 = prev;
            prev = temp;
        }

        return prev+prev2;

    }
};