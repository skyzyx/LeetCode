// LeetCode #121: Best Time to Buy and Sell Stock

/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

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