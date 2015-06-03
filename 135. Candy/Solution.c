// LeetCode #135: Candy

/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

int candy(int* ratings, int ratingsSize) {
    if (ratingsSize == 0)
        return 0;
        
    int res[ratingsSize];
    for (int i = 0; i < ratingsSize; i++)
        res[i] = 1;
        
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i-1])
            res[i] = res[i-1] + 1;
    }
    
    int candyNums = 0;
    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i+1] && res[i] <= res[i+1])
            res[i] = res[i+1] + 1;
            
        candyNums += res[i];
    }
    candyNums += res[ratingsSize - 1];
    return candyNums;
}