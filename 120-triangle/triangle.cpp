class Solution {
public:

    void ppv(vector<vector<int>>& arr){
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void pv(vector<int>& arr){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        if(triangle.empty()) return 0;
        int m = triangle.size();
        vector<int> prev(m,0);
        vector<int> curr(m,0);

        prev[0] = triangle[0][0];
        curr[0] = triangle[0][0];
        
        for(int i=0;i<triangle.size();i++){
            for(int j=0;j<=i;j++){
                if(i==0 && j==0) curr[j] = triangle[i][j];
                else if(j==0) curr[j] = triangle[i][j] + prev[j];
                else if(j<i) curr[j] = triangle[i][j] + min(prev[j],prev[j-1]); 
                else curr[j] =  triangle[i][j] + prev[j-1];
            }
            prev = curr;
        }
        return *min_element(prev.begin(),prev.end());
    }
};