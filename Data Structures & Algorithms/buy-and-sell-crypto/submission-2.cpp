class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int max_profit = 0;
        int size_price = prices.size();
        for (int right = 0; right < size_price; right++) {
            if(prices[right] > prices[left]){
                max_profit = max(max_profit, prices[right] - prices[left]);
            } else if (prices[right] < prices[left]) {
                left = right;
            }
        }
        return max_profit;
    }
};
