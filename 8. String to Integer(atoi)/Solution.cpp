// LeetCode #8: String to Integer (atoi)

/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

class Solution {
private:
    int maxDiv10 = INT_MAX / 10;

public:
    int myAtoi(string str) {
        int i = 0;
        int n = str.size();
        
        while (i < n && str[i] == ' ')
            i++;
            
        int sign = 1;
        if (i < n && str[i] == '+')
            i++;
        else if (i < n && str[i] == '-') {
            i++;
            sign = -1;
        }
        
        int res = 0;
        while (i < n && isdigit(str[i])) {
            int digit = str[i] - '0';
            if (res > maxDiv10 || res == maxDiv10 && digit >= 8)
                return sign == 1? INT_MAX: INT_MIN;
            
            res = res * 10 + digit;
            i++;
        }
        return res * sign;
    }
};