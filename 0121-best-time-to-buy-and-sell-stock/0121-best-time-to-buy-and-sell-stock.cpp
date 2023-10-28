class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int mini = prices[0];
        for(auto p:prices){
            mini = min(mini,p);
            maxi = max(maxi,p-mini);
        }   
        return maxi;
    }
};