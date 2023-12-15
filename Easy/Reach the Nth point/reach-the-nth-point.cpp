//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		    int ans = 0;
		    long long int mod = 1e9+7;
		    int f = 1,s=2,t=0;
		    if(n==1) return f;
		    if(n==2) return s;
		    for(int i=3;i<=n;i++){
		        t = (s%mod+f%mod)%mod;
		        f=s;
		        s=t;
		    }
		    return t;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends