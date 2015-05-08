class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0)
            return 0;
            
        stack<string> s;
        for (string word: tokens) {
            if (word != "+" && word != "-" && word != "*" && word != "/") {
                s.push(word);
            } else {
                int num1 = stoi(s.top()); // int num1 = (int)s.top() did NOT work.
                s.pop();
                int num2 = stoi(s.top());
                s.pop();
                
                switch(word[0]) { // Has to convert string to char.
                    case '+':
                        s.push(to_string(num2 + num1)); // to_string().
                        break;
                    case '-':
                        s.push(to_string(num2 - num1));
                        break;
                    case '*':
                        s.push(to_string(num2 * num1));
                        break;
                    case '/':
                        s.push(to_string(num2 / num1));
                        break;
                    default:
                        break;
                }
            }
        }
        
        return stoi(s.top());
    }
};