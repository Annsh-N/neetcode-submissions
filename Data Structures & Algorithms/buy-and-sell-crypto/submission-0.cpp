class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = INT_MAX;
        int sellPrice = 0;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < buyPrice) {
                buyPrice = price;
                sellPrice = 0;
            }
            sellPrice = max(sellPrice, price);

            maxProfit = max(maxProfit, sellPrice - buyPrice);
        }

        return maxProfit;
    }
};
