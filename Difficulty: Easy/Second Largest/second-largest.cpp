//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        int maxi = INT_MIN;
        int maxi1 = INT_MIN;
        for(int x : arr){
            if(x>maxi){
                maxi1 = maxi;
                maxi = x;
            }else if(x>maxi1 && x<maxi){
                maxi1 = x;
            }
        }
        return maxi1<maxi?maxi1:-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends