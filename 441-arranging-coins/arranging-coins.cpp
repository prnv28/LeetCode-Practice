class Solution {
public:
    int arrangeCoins(int n) {
        int left = 0;
        int right = n;
        int ans = 0;
        while(left<=right){
            int mid = (left+right)/2;
            cout<<mid<<endl;
            long long k = (long long ) mid * (mid+1)/2;
             if(k>n){
                right = mid-1;
            }else{
                left = mid+1;
                ans = mid;
            }
        }
        return ans;
    }
};