class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s1;
        int result;
        for (string token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = s1.top();
                s1.pop();
                int a = s1.top();
                s1.pop();
                if (token == "+")
                    result = a + b;
                else if (token == "-")
                    result = a - b;
                else if (token == "*")
                    result = a * b;
                else
                    result = a / b;
                s1.push(result);
            } else
                s1.push(stoi(token));
        }
        return s1.top();
    }
};