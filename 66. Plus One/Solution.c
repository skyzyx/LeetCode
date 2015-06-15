// LeetCode #66: Plus One

/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (carry + digits[i] == 10) {
            digits[i] = 0;
            carry = 1;
        } else {
            digits[i] += carry;
            return digits;
        }
    }
    
    returnSize[0] = 1;
    for (int i = 0; i < digitsSize; i++)
        returnSize[i+1] = digits[i];
        
    return returnSize;
}