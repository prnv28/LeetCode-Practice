//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

#include<numeric>
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        long long total = 0;
        for(int i=0;i<n;i++){
            total+=a[i];
        }
        long long pre = 0;
        for(int i=0;i<n;i++){
            long long rem = total - pre - a[i];
            if(pre==rem) return i+1;
            pre += a[i];
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends