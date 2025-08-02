class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for(int i=1;i<=n/2;i++){
            ans += (n-(2*(i-1)+1));
        }
        return ans;
    }
};