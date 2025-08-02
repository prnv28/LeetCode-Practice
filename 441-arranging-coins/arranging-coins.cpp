class Solution {
public:
    int arrangeCoins(int n) {
        // int left=0,right=n;
        // int ans = 0;
        // while(left<=right){
        //     int mid = (left+right)/2;
        //     long long coins = (long long)mid*(mid+1)/2;
        //     if(coins>n){
        //         right = mid-1;
        //     }else{
        //         left = left+1;
        //         ans = max(ans,mid);
        //     }
        // }
        // return ans;
        return (int) (sqrt(1+(long long) 8*n) - 1)/2;
    }
};