int maxProfit(int* prices, int pricesSize) {
    if (prices == NULL || pricesSize < 2)
        return 0;
        
    int maxProfit = 0;
    int lowest = prices[0];
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] - lowest > maxProfit)
            maxProfit = prices[i] - lowest;
            
        if (prices[i] < lowest)
            lowest = prices[i];
    }
    return maxProfit;
}