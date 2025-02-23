// Sample Input
// 3
// 6
// because can do must we what
// wedowhatwemustbecausewecan
// 2
// hello planet
// helloworld
// 3
// ab abcd cd
// abcd

// Sample Output 
// we do what we must because we can
// WRONG PASSWORD
// ab cd

// Explanation 
// Sample Case #00: "wedowhatwemustbecausewecan" is the concatenation of passwords {"we", "do", "what", "we", "must", "because", "we", "can"}. That is
// loginAttempt = pass[5] + pass[3] + pass[6] + pass[5] +  pass[4] + pass[1] + pass[5] + pass[2]
// Note that any password can repeat any number of times.

// Sample Case #01: We can't create string "helloworld" using the strings {"hello", "planet"}.
// Sample Case #02: There are two ways to create loginAttempt ("abcd"). Both pass[2] = "abcd" and pass[1] + pass[3] = "ab cd" are valid answers.

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> memo;

string solve(string loginAttempt, unordered_set<string> &passwordSet) {
    if (loginAttempt.empty()) return "";
    if (memo.count(loginAttempt)) return memo[loginAttempt];

    for (int i = 1; i <= loginAttempt.size(); i++) {
        string prefix = loginAttempt.substr(0, i);
        if (passwordSet.count(prefix)) {
            string suffixResult = solve(loginAttempt.substr(i), passwordSet);
            if (suffixResult != "WRONG PASSWORD") {  //If it is already a Not password word then it is a wrong password
                return memo[loginAttempt] = (prefix + (suffixResult.empty() ? "" : " " + suffixResult)); //Each intermediate step is stored so repeated once be memoized
            }
        }
    }
    return memo[loginAttempt] = "WRONG PASSWORD";
}

void passwordCracker(vector<string> passwords, string loginAttempt) {
    unordered_set<string> passwordSet(passwords.begin(), passwords.end());
    memo.clear();
    string result = solve(loginAttempt, passwordSet);
    cout << result << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> passwords(n);
        for (int i = 0; i < n; i++) {
            cin >> passwords[i];
        }
        string loginAttempt;
        cin >> loginAttempt;
        passwordCracker(passwords, loginAttempt);
    }
    return 0;
}
