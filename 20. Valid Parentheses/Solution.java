// LeetCode #20: Valid Parentheses

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

public class Solution {
    public boolean isValid(String s) {
        if (s == null || s.length() % 2 != 0)
            return false;
            
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0; i < s.length(); i++) {
            char letter = s.charAt(i);
            if (letter == '(' || letter == '{' || letter == '[') {
                stack.push(letter);
                continue;
            } 
            
            if (!stack.isEmpty()) {
                char current = stack.peek();
                if ((letter == '(' && current == ')') || (letter == '{' && current == '}') || (letter == '[' && current == ']'))
                    stack.pop();
            } else {
                return false;
            } 
        }
        
        return stack.isEmpty();
    }
}