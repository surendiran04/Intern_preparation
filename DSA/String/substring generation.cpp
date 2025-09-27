// C++ program to find all the substrings of given string

// for a string of length n , total substrings will be n*(n+1)/2;

#include <bits/stdc++.h>
using namespace std;
vector<string> findSubstrings(string &s) {
    vector<string> res;
    for(int i = 0; i < s.length(); i++) {
        for(int j = i; j < s.length(); j++) { 
            // substr function takes starting index
            // and length as parameters
            res.push_back(s.substr(i, j-i+1));
        }
    }
    return res;
}

void subString(string &s, int n, int index, string &cur, vector<string> &res) { //recursive approach

    // if we have reached the 
    // end of the string
    if (index == n) {
        return;
    }
    // add the character s[index] 
    // to the current string
    cur.push_back(s[index]);
    // add the current string in result
    res.push_back(cur);
    // move to next index
    subString(s, n, index + 1, cur, res);

    // remove the current character
    // from the current string 
    cur.pop_back();
    
    // if current string is empty
    // skip the current index to
    // start the new substring
    if(cur.empty()) {
        subString(s, n, index + 1, cur, res);
    }
}

vector<string> findSubstrings(string s) {
    vector<string> res;   // to store all substrings
    
    string cur = ""; // to store current string
    subString(s, s.length(), 0, cur, res);
    return res;
}

int main() {
    string s = "abc";  
    vector<string> res = findSubstrings(s);
    for(auto i:res) {
        cout<< i <<" "; //a ab abc b bc c 
    }
    return 0;
}

