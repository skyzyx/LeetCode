// LeetCode #150: Evaluate Reverse Polish Notation

/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

public class Solution {
    public int evalRPN(String[] tokens) {
        if (tokens == null || tokens.length == 0)
            return 0;
        Stack<String> s =  new Stack<String>();
        
        for (String word: tokens) {
            if (!word.equals("+") && !word.equals("-") && !word.equals("*") && !word.equals("/")) {
                s.push(word);
            } else {
                int num1 = Integer.valueOf(s.pop());
                int num2 = Integer.valueOf(s.pop());
                
                switch(word) { 
                    case "+":
                        s.push(String.valueOf(num2 + num1)); // num2 is the first operand.
                        break;
                    case "-":
                        s.push(String.valueOf(num2 - num1)); // num2 is the first operand.
                        break;
                    case "*":
                        s.push(String.valueOf(num2 * num1)); // num2 is the first operand.
                        break;
                    case "/":
                        s.push(String.valueOf(num2 / num1)); // num2 is the first operand.
                        break;
                    default:
                        break;
                }
            }
        }
        
        return Integer.valueOf(s.pop());
    }
}