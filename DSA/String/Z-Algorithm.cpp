#include <bits/stdc++.h>
using namespace std;

vector<int> computeZ(string s) {
    int n = s.size();
    vector<int> Z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) Z[i] = min(r - i + 1, Z[i - l]);
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) Z[i]++;
        if (i + Z[i] - 1 > r) l = i, r = i + Z[i] - 1;
    }
    return Z;
}

void ZSearch(string text, string pat) {
    string s = pat + "$" + text;
    vector<int> Z = computeZ(s);
    for (int i = 0; i < Z.size(); i++) {
        if (Z[i] == pat.size()) 
            cout << "Pattern found at index " << i - pat.size() - 1 << "\n";
    }
}

int main() {
    ZSearch("aabcaabxaaaz", "aab");
}
