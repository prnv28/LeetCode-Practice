class Solution {
public:
    int trap(vector<int>& arr) {
        int lmax=0, rmax=0,l=0,r=arr.size()-1,i=0,total=0;
        while(l<r){
            if(arr[r]>=arr[l]){
                if(arr[l]<lmax){
                    total += lmax-arr[l];
                }else{
                    lmax = arr[l];
                }
                l++;
            }else{
                if(arr[r]<rmax){
                    total += rmax - arr[r];
                }else{
                    rmax = arr[r];
                }
                r--;
            }
        }
        return total;
        
    }
};