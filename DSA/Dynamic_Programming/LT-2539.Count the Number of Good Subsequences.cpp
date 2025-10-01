//Count the no of good subsequence in a string , a good subsequence musty have freq of all char as same
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 10001;
const int MOD = 1e9 + 7;
vector<long long> f(N, 1), g(N, 1);

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void precompute() {
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i % MOD;
        g[i] = modPow(f[i], MOD - 2, MOD);
    }
}

long long comb(int n, int k) {
    return f[n] * g[k] % MOD * g[n - k] % MOD;
}

class Solution {
public:
    int countGoodSubsequences(string s) {
        unordered_map<char, int> cnt;
        for (char ch : s) {
            cnt[ch]++;
        }
        
        precompute();
        
        int maxFreq = 0;
        for (auto& p : cnt) {
            if (p.second > maxFreq) {
                maxFreq = p.second;
            }
        }
        
        long long ans = 0;
        for (int i = 1; i <= maxFreq; ++i) {
            long long x = 1;
            for (auto& p : cnt) {
                if (p.second >= i) {
                    x = x * (comb(p.second, i) + 1) % MOD;
                }
            }
            ans = (ans + x - 1) % MOD;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string word = "abcd";
    int result = solution.countGoodSubsequences(word);
    cout << "The number of good subsequences is: " << result << endl; //15 2^4-1=15 since empty string is not a good substring
    return 0;
}
//baab - 11
//abca - 12
//aba - 6
//abbabc - 31
