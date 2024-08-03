#include <iostream>
#include <string>
#include <cctype>
#include <stack>

double evaluateExpression(const std::string& expr) {
    std::stack<double> values;
    std::stack<char> ops;

    auto applyOp = [](char op, double b, double a) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return 0.0;
    };

    for (size_t i = 0; i < expr.size(); ++i) {
        if (isspace(expr[i])) continue;
        
        if (isdigit(expr[i])) {
            double value = 0;
            while (i < expr.size() && isdigit(expr[i])) {
                value = value * 10 + (expr[i] - '0');
                ++i;
            }
            --i;
            values.push(value);
        } else if (expr[i] == '(') {
            ops.push(expr[i]);
        } else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(op, val2, val1));
            }
            ops.pop();
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            while (!ops.empty() && ((ops.top() == '*' || ops.top() == '/') || 
                   (expr[i] == '+' || expr[i] == '-') && (ops.top() == '+' || ops.top() == '-'))) {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(op, val2, val1));
            }
            ops.push(expr[i]);
        }
    }

    while (!ops.empty()) {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(op, val2, val1));
    }

    return values.top();
}

int main() {
    std::string expression = "3 + 5 * (2 - 8)";
    std::cout << "Result: " << evaluateExpression(expression) << std::endl;
    
    return 0;
}
