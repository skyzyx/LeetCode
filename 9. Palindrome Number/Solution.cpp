// LeetCode #9: Palindrome Number

/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        // Input:	-2147483648
        // Output:	true
        // Expected:	false 
        if (x < 0)
            return false;
            
        int div = 1;
        while (div <= x / 10)
            div *= 10;
            
        while (x > 0) {
            if (x / div != x % 10)
                return false;
                
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
};