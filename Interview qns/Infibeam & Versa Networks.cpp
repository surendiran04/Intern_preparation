Infibeam:
1.Generate the Nth element which contains M digits
The ID starts 0-Z (0-9 then A-Z) 
let's say of m=4 then N=1000 element=A000
If M=2
n=0 → 00
n=1 → 01
…
n=99 → 99
n=100 → A0
n=101 → A1
…
n=109 → A9
n=110 → B0
…
n=359 → Z9
n=360 → AA0
m=3, n=1000 → A00
  
#include <bits/stdc++.h>
using namespace std;

// convert index -> letters (like Excel columns: A, B, ..., Z, AA, AB, ...)
string toLetters(long long index) {
    string res;
    while (index >= 0) {
        res.push_back('A' + (index % 26));
        index = index / 26 - 1; // Excel-style decrement
    }
    reverse(res.begin(), res.end());
    return res;
}

string generateID(long long n, int m) {
    long long blockSize = pow(10, m - 1); // digits on right
    long long totalNumeric = pow(10, m);  // pure digits (0...999 for m=3 etc.)

    // Case 1: within pure digits
    if (n < totalNumeric) {
        string num = to_string(n);
        while ((int)num.size() < m) num = "0" + num;
        return num;
    }

    // Case 2: after digits -> letters + digits
    n -= totalNumeric; // offset into lettered IDs

    long long lettersIndex = n / blockSize; // which letter sequence
    long long numPart = n % blockSize;      // numeric suffix

    string letters = toLetters(lettersIndex);
    string num = to_string(numPart);

    // Pad numeric to (m - letters.size())
    while ((int)num.size() < m - (int)letters.size()) num = "0" + num;

    return letters + num;
}

int main() {
    int m;
    long long n;
    cout << "Enter m and n: ";
    cin >> m >> n;
    cout << "ID: " << generateID(n, m) << "\n";
    return 0;
}
2. Calculate the height of BST and eliminate if the node's value contains odd value
  note:
    if a tree contains only one then height=0
    if a tree contains zero nodes then also height=0
    if a tree's longest path contains a odd value node simply not consider the edge
  
  int getheight(Node* root){
    if(root==nullptr){
        return 0;
    }
    if(root->left==nullptr && root->right==nullptr){
        return 0;
    }
    return max(0,Height(root));
}
int Height(Node* root){
    if(root==nullptr){
        return -1;
    }
    int l=Height(root->left);
    int r=Height(root->right);
    if(root->data & 1){
        return max(l,r);
    }
    return 1+max(l,r);
}

//Versa Networks
// 1.Postfix to Infix conversion
// input: abc+* op:(a*(b+c))
#include <string>
#include <stack>
#include <cctype> // For isalnum
#include <iostream>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string postToInfix(const string& s) {
    stack<string> st;
    for (char ch : s) {
        if (isalnum(ch)) {
            st.push(string(1, ch));
        } else if (isOperator(ch)) {
            if (st.size() < 2) {
                // Handle invalid expression (not enough operands)
                // For this problem, you can assume valid input.
                return "Error: Invalid Postfix Expression"; 
            }
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            
            string newExp = "(" + op1 + string(1, ch) + op2 + ")";
            st.push(newExp);
        }
    }
    
    if (st.size() == 1) {
        // The final result is at the top of the stack
        return st.top();
    } else {
        // Handle invalid expression (too many operands)
        return "Error: Invalid Postfix Expression";
    }
}
2. Merge 2 sorted arrays
3. Given a binary string as input we have invert the bits initially like 0 to 1 and 1 to 0.convert the new binary string to number.
  Also check whether it is prime or not

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool checkPrime(int n){
    if(n<=1){
        return false;
    }
    if(n==2){
        return true;
    }
    if(n%2==0){
        return false;
    }
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int binaryToDecimal(string s){
    int n = s.length();
    int res = 0;
    int i = 1;
    for(int j=n-1;j>=0;j--){
        char ch = s[j];
        int digit = (ch-'0');
        res = res + digit*i;
        i = i*2;
    }
    return res;
}

void BinarySwap(string s){
    string t=s;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(t[i]=='1'){
            t[i]='0';
        }
        else{
            t[i]='1';
        }
    }
    int res=binaryToDecimal(t);
    string prime=(checkPrime(res))?"True":"False";
    cout<<res<<" "<<prime<<endl;
}

int main() {
    // Example usage:
    // If the input is "10110", it inverts to "01001" (decimal 9).
    // 9 is not prime, so it should output "9 False".
    BinarySwap("10110");

    // Example usage:
    // If the input is "001", it inverts to "110" (decimal 6).
    // 6 is not prime, so it should output "6 False".
    BinarySwap("001");
    
    // Example usage:
    // If the input is "110", it inverts to "001" (decimal 1).
    // 1 is not prime, so it should output "1 False".
    BinarySwap("110");
    
    // Example usage:
    // If the input is "000", it inverts to "111" (decimal 7).
    // 7 is prime, so it should output "7 True".
    BinarySwap("000");

    return 0;
}
