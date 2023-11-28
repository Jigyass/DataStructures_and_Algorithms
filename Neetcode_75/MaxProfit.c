int maxProfit(int* prices, int pricesSize) {
    int minPrice = 100000;  // Assuming stock prices won't go beyond 10^4
    int maxProfit = 0;

    for (int i = 0; i < pricesSize; ++i) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;
}
