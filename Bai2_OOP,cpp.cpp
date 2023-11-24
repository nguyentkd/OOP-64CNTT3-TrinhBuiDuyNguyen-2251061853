#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Calculator {
public:
    int calculateExpression(const string& expression) {
        int result = 0;
        int currentNumber = 0;
        int sign = 1;
        int i = 0;

        while (i < expression.length()) {
		    char currentChar = expression[i];
		    if (isdigit(currentChar)) {
		        currentNumber = (currentNumber * 10) + (currentChar - '0');
		    }
		    else if (currentChar == '-') {
		        result += sign * currentNumber;
		        currentNumber = 0;
		        sign = -1;
		    }
		    else if (currentChar == '+') {
		        result += sign * currentNumber;
		        currentNumber = 0;
		        sign = 1;
		    }
		    else if (currentChar == '*') {
		        result += sign * currentNumber;
		        currentNumber = 0;
		        i++;
		        result *= calculateExpression(expression.substr(i));
		        break;
		    }
		    else if (currentChar == '(') {
		        int startIndex = i + 1;
		        int endIndex = findMatchingBracket(expression, startIndex);
		        string subExpression = expression.substr(startIndex, endIndex - startIndex);
		        result += sign * calculateExpression(subExpression);
		        currentNumber = 0;
		        i = endIndex + 1;
		    }
		    else if (expression.substr(i, 3) == "abs") {
		        int startIndex = i + 4;
		        int endIndex = findMatchingBracket(expression, startIndex);
		        string absExpression = expression.substr(startIndex, endIndex - startIndex);
		        result += sign * abs(calculateExpression(absExpression));
		        currentNumber = 0;
		        i = endIndex + 1;
		    }
		    i++;
		}

        return result + (sign * currentNumber);
    }

private:
    int findMatchingBracket(const string& expression, int startIndex) {
        int count = 1;
        int endIndex = startIndex;

        while (count > 0 && endIndex < expression.length()) {
            endIndex++;
            if (expression[endIndex] == '(') {
                count++;
            }
            else if (expression[endIndex] == ')') {
                count--;
            }
        }

        return endIndex;
    }
};

int main() {
    Calculator calculator;
    string expression;

    getline(cin, expression);

    int result = calculator.calculateExpression(expression);
    cout << result;

    return 0;
}
