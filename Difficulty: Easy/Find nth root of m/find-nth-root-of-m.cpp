class Solution {
  public:
    int power(int num, int p){
        int ans = 1;
        int nn = num;
        while(p>1){
            if(p%2==0){
                nn = nn * nn;
                p /=2;
            }else{
                ans *= num;
                p -= 1;
            }
        }
        
        return ans*nn;
    }
    int nthRoot(int n, int m) {
       int ans = 1.0;
       int end = m;
       int start = 1;
       while(start<=end){
           int mid = (start+end)/2;
           int powe = power(mid,n);
           if(m>powe){
               start = mid+1;
           }else if(m<powe){
               end = mid-1;
           }else{
               return mid;
           }
       }
       return -1;
    }
};