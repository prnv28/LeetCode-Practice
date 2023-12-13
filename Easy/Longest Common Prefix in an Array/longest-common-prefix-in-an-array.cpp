//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {   
        string result = "";
        int mini = INT_MAX;
        for(int i=0;i<N;i++){
            if(arr[i].size()<mini){
                mini = arr[i].size();
            }
        }
        for(int i =0;i<mini;i++){
            char c = arr[0][i];
            for(int j=1;j<N;j++){
                if(arr[j][i]!=c) return result.size()?result:"-1";
            }
            result += c;
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends