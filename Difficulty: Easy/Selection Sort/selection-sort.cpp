//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends
class Solution
{
    public:
    int select(int arr[], int i,int n)
    {   
        int mini = i;
        for(int ind=i;ind<n;ind++){
            if(arr[mini]>arr[ind]){
                mini = ind;
            }
        }
        return mini;
    }
     
    void selectionSort(int arr[], int n)
    {
       int i=0;
       while(i<n){
           int min_ind = select(arr,i,n);
           swap(arr[i],arr[min_ind]);
           i++;
       }
    }
};

//{ Driver Code Starts.
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
    ob.selectionSort(arr, n);
    printArray(arr, n);
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends