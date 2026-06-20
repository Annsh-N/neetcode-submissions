class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            buyPrice = min(buyPrice, price);
            maxProfit = max(maxProfit, price - buyPrice);
        }

        return maxProfit;
    }
};
