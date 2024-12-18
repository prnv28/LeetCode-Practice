class Solution {
public:
    int algo(int ind,int min_price,vector<int>& prices){
        if(ind>=prices.size()) return 0;
        return max(prices[ind]-min_price,algo(ind+1,min(min_price,prices[ind]),prices));
    }
    int maxProfit(vector<int>& prices) {
        // return algo(0,INT_MAX,prices);
        int min_prices = INT_MAX;
        int max_profit = 0;
        for(int i=0;i<prices.size();i++){
            max_profit = max(prices[i]-min_prices,max_profit);
            min_prices = min(min_prices,prices[i]);
        }
        return max_profit;
    }
};