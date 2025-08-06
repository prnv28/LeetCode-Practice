class Solution {
public:
    int arrangeCoins(int n) {
        int left = 0;
        int right = n;
        int ans = 0;
        while(left<=right){
            int mid = (left+right)/2;
            long long k = (long long ) mid * (mid+1)/2;
             if(k>n){
                right = mid-1;
            }else{
                left = left+1;
                ans = mid;
            }
        }
        return ans;
    }
};