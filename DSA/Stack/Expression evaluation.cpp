#include <bits/stdc++.h>
using namespace std;

int applyOp(int a, int b, char op) {
    switch(op) {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': if(b==0) throw runtime_error("Division by zero"); return a/b;
        case '^': return (int)pow(a,b);
    }
    throw runtime_error("Unknown operator");
}

bool isOperator(char c){
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

int precedence(char op){
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}

bool isRightAssociative(char op){
    return op=='^';
}

// ---------- POSTFIX ----------
int evaluatePostfix(const string &expr){
    stringstream ss(expr);
    string tok;
    stack<int> st;
    while(ss >> tok){
        if(tok.size()==1 && isOperator(tok[0])) {
            if(st.size() < 2) throw runtime_error("Invalid postfix");
            int b=st.top(); st.pop();
            int a=st.top(); st.pop();
            st.push(applyOp(a,b,tok[0]));
        } else {
            st.push(stoi(tok));
        }
    }
    if(st.size()!=1) throw runtime_error("Invalid postfix final state");
    return st.top();
}

// ---------- PREFIX ----------
int evaluatePrefix(const string &expr){
    vector<string> toks;
    stringstream ss(expr);
    string tok;
    while(ss >> tok) toks.push_back(tok);
    stack<int> st;
    for(int i=(int)toks.size()-1;i>=0;--i){
        string t=toks[i];
        if(t.size()==1 && isOperator(t[0])){
            if(st.size()<2) throw runtime_error("Invalid prefix");
            int a=st.top(); st.pop();
            int b=st.top(); st.pop();
            st.push(applyOp(a,b,t[0]));
        } else {
            st.push(stoi(t));
        }
    }
    if(st.size()!=1) throw runtime_error("Invalid prefix final state");
    return st.top();
}

// ---------- INFIX -> POSTFIX ----------
string infixToPostfix(const string &in){
    stringstream ss(in);
    string tok;
    vector<string> out;
    stack<char> ops;
    while(ss >> tok){
        if(tok=="(") {
            ops.push('(');
        } else if(tok==")") {
            while(!ops.empty() && ops.top()!='('){
                out.push_back(string(1, ops.top()));
                ops.pop();
            }
            if(ops.empty()) throw runtime_error("Mismatched parentheses");
            ops.pop(); // remove '('
        } else if(tok.size()==1 && isOperator(tok[0])) {
            char op=tok[0];
            while(!ops.empty() && ops.top()!='(' &&
                 (precedence(ops.top())>precedence(op) ||
                 (precedence(ops.top())==precedence(op) && !isRightAssociative(op)))){
                out.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(op);
        } else {
            out.push_back(tok); // operand
        }
    }
    while(!ops.empty()){
        if(ops.top()=='(' || ops.top()==')') throw runtime_error("Mismatched parentheses");
        out.push_back(string(1, ops.top()));
        ops.pop();
    }
    string res;
    for(size_t i=0;i<out.size();++i){
        if(i) res += " ";
        res += out[i];
    }
    return res;
}

int evaluateInfix(const string &in){
    return evaluatePostfix(infixToPostfix(in));
}

// ---------- MAIN ----------
int main(){
    cout << "\n=== Expression evaluation examples ===\n";

    // Postfix
    string postfix="2 3 1 * + 9 -"; // 2+(3*1)-9 = -4
    cout << "Postfix: " << postfix << " = " << evaluatePostfix(postfix) << "\n";

    // Prefix
    string prefix="- + 2 * 3 1 9"; // - (2 + (3*1)) 9
    cout << "Prefix: " << prefix << " = " << evaluatePrefix(prefix) << "\n";

    // Infix
    string infix="2 + 3 * 1 - 9 + ( 1 + 3 )";
    cout << "Infix: " << infix 
         << " -> Postfix: " << infixToPostfix(infix)
         << " -> Value: " << evaluateInfix(infix) << "\n";

    // Power operator
    string inf2="( 3 + 4 ) * 2 ^ 2";
    cout << "Infix: " << inf2 
         << " -> Postfix: " << infixToPostfix(inf2)
         << " -> Value: " << evaluateInfix(inf2) << "\n";

    return 0;
}
