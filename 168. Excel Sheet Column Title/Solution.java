public class Solution {
    public String convertToTitle(int n) {
        if (n <= 0)
            return null;
            
        StringBuilder res = new StringBuilder();
        while (n > 0) {
            n--;
            char letter = (char) (n % 26 + 'A');
            res.append(letter);
            n /= 26;
        }
        res.reverse();
        return res.toString();
    }
}