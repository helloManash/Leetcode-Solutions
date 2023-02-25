class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin.tie(NULL);
        int profit_ending_here = 0, max_profit = 0, buy = prices[0];
        for(int i = 1;i < prices.size(); i++){
            
            profit_ending_here = max(prices[i] - buy, 0);
            max_profit = max(profit_ending_here, max_profit);
            buy =  min(buy, prices[i]);
            
        }
        return max_profit;
    }
};