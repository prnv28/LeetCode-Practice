//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	
	ll countStrings(int n) {
        ll total = 0;
	    ll total1 = 2;
	    ll total2 = 3;
	    if(n==1) return total1;
	    if(n==2) return total2;
	    ll mod = 1e9 + 7;
	    for(int i=3;i<=n;i++){
	        total = ((total1%mod)+(total2%mod))%mod;
	        total1 = total2;
	        total2 = total;
	    }
	    return (total%mod);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends