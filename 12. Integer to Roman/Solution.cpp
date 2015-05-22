class Solution {
public:
    string intToRoman(int num) {
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};    
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        string res = "";
        int arraySize = sizeof(value) / sizeof(value[0]); // std::vector has a method size() which returns the number of elements in the vector.

        for (int i = 0; i < arraySize; i++) {
            while (num >= value[i]) {
                num -= value[i];
                res += symbol[i];
            }
        }
        return res;
    }
};