// Need to find the points for the given answers by the students for the evaluation for eqn.
// 5 points - crt op
// 2 points - partial (not considering BODMAS)
// 0 points - wrong op

// Enter equation: 5*4-3*2
// Correct answer: 14
// Enter number of students: 4
// Enter answer for student 1: 14
// Enter answer for student 2: 10
// Enter answer for student 3: -10
// Enter answer for student 4: 90
// Total points: 9

// Enter equation: 29*17-29*19+28-2
// Correct answer: -32
// Enter number of students: 6
// Enter answer for student 1: -32
// Enter answer for student 2: -37352
// Enter answer for student 3: -6586
// Enter answer for student 4: 8842
// Enter answer for student 5: 60
// Enter answer for student 6: 20880
// Total points: 13


#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

// Memoization map to store intermediate results
unordered_map<string, vector<int>> memo;

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
// Function to check operator precedence
bool hasPrecedence(char current, char prev) {
    if ((current == '*' || current == '/') && (prev == '+' || prev == '-')) {
        return false;
    }
    return true;
}

// Function to apply an operator to the top two values in the stack
void applyOperator(stack<int>& values, char op) {
    int b = values.top();
    values.pop();
    int a = values.top();
    values.pop();

    switch (op) {
        case '+':
            values.push(a + b);
            break;
        case '-':
            values.push(a - b);
            break;
        case '*':
            values.push(a * b);
            break;
        case '/':
            values.push(a / b);
            break;
    }
}
// Function to evaluate the equation using BODMAS rules
int evaluateBodmas(const string& equation) {
    stack<int> values;
    stack<char> operators;
    int num = 0;

    for (size_t i = 0; i < equation.length(); i++) {
        char c = equation[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0'); // Build the number
        }

        if (i == equation.length() - 1 || !isdigit(c)) {
            values.push(num);
            num = 0;

            while (!operators.empty() && hasPrecedence(c, operators.top())) {
                applyOperator(values, operators.top());
                operators.pop();
            }

            if (i < equation.length() - 1) {
                operators.push(c);
            }
        }
    }

    while (!operators.empty()) {
        applyOperator(values, operators.top());
        operators.pop();
    }

    return values.top();
}



// Function to evaluate all possible results by splitting the equation at operators
vector<int> evaluateAllPossibleResults(const string& equation) {
    if (memo.find(equation) != memo.end()) {
        return memo[equation];
    }

    vector<int> results;

    bool hasOperator = false;
    for (char c : equation) {
        if (isOperator(c)) {
            hasOperator = true;
            break;
        }
    }

    if (!hasOperator) {
        results.push_back(stoi(equation));
        memo[equation] = results;
        return results;
    }

    for (size_t i = 0; i < equation.length(); i++) {
        char c = equation[i];
        if (isOperator(c)) {
            string left = equation.substr(0, i);
            string right = equation.substr(i + 1);

            vector<int> leftResults = evaluateAllPossibleResults(left);
            vector<int> rightResults = evaluateAllPossibleResults(right);

            for (int l : leftResults) {
                for (int r : rightResults) {
                    switch (c) {
                        case '+':
                            results.push_back(l + r);
                            break;
                        case '-':
                            results.push_back(l - r);
                            break;
                        case '*':
                            results.push_back(l * r);
                            break;
                        case '/':
                            if (r != 0) {
                                results.push_back(l / r);
                            }
                            break;
                    }
                }
            }
        }
    }

    memo[equation] = results;
    return results;
}

int main() {
    string equation;
    cout << "Enter equation: ";
    getline(cin, equation);

    int correctAnswer = evaluateBodmas(equation);
    cout << "Correct answer: " << correctAnswer << endl;

    vector<int> possibleResults = evaluateAllPossibleResults(equation);
    unordered_set<int> partialAnswers;
    for (int res : possibleResults) {
        if (res != correctAnswer) {
            partialAnswers.insert(res);
        }
    }

    int numberOfStudents;
    cout << "Enter number of students: ";
    cin >> numberOfStudents;

    int totalPoints = 0;
    for (int i = 0; i < numberOfStudents; i++) {
        int answer;
        cout << "Enter answer for student " << (i + 1) << ": ";
        cin >> answer;

        if (answer == correctAnswer) {
            totalPoints += 5;
        } else if (partialAnswers.find(answer) != partialAnswers.end()) {
            totalPoints += 2;
        }
    }

    cout << "Total points: " << totalPoints << endl;

    return 0;
}
