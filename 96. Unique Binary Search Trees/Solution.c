// LeetCode #96: Unique Binary Search Trees

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

int numTrees(int n) {
    if (n <= 0)
        return 0;
        
    int* dp; // int dp[n+1] = {0}; Line 5: variable-sized object may not be initialized
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];  
}