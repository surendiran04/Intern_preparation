#include <bits/stdc++.h>  
using namespace std;

int countPalindromes(string s) { 
    int n = s.size(), count = 0;
    for (int center = 0; center < 2*n - 1; center++) {  //Expand around center 
        int l = center / 2;
        int r = l + center % 2;
        while (l >= 0 && r < n && s[l] == s[r]) {
            count++;
            l--; r++;
        }
    }
    return count;
}

int main() {
    vector<string> strs = {"aaa", "abc", "aba"};
    for (string s : strs) {
        cout << countPalindromes(s) << " ";
    }
    return 0;
}
