# LeetCode #150: Evaluate Reverse Polish Notation

'''
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
'''

class Solution:
    # @param {string[]} tokens
    # @return {integer}
    def evalRPN(self, tokens):
        if tokens == None or len(tokens) == 0:
            return 0
            
        stack = []
        for word in tokens:
            if word not in ["+", "-", "*", "/"]:
                stack.append(int(word))
            else:
                num1 = stack.pop()
                num2 = stack.pop()
                
                if word == "+":
                    stack.append(num2 + num1)
                elif word == "-":
                    stack.append(num2 - num1)
                elif word == "*":
                    stack.append(num2 * num1)
                else:
                    if num1 * num2 < 0:
                        stack.append(-((-num2) / num1))
                    else:
                        stack.append(num2 / num1)
                
        return stack.pop()
'''
Input:	["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output:	12
Expected:	22
'''
# For python, 3 / (-5) = -1, which is ridiculous.
        