// You are given N strings consisting of lowercase Latin letters. You need to choose exactly K strings from these N strings such that their longest common prefix (LCP) is as long as possible.
// The longest common prefix of a set of strings is defined as the longest string that is a prefix of all strings in that set. For example, the LCP of ["apple", "apply", "apartment"] is "ap" with length 2.
// Input
// The first line contains two integers N and K (1 ≤ N ≤ 3000, 2 ≤ K ≤ N), where N is the number of strings and K is the size of the subset you need to choose.
// The next N lines contain strings S1, S2, ..., SN, consisting of lowercase Latin letters (a-z).
// The sum of the lengths of all strings does not exceed 3000.
// Output
// Print a single integer — the maximum possible length of the longest common prefix that can be achieved by selecting exactly K strings from the given N strings.

// Examples
// Input
// 4 2
// [prefix,preliminary,presentation,prelude]
// Output
// 4
// Detailed Explanation for Test Case 1:
// In the first test case, n = 4 and k = 2, so possible combinations are:

// [prefix, preliminary]: LCP = 'pre', Length = 3
// [prefix, presentation]: LCP = 'pre', Length = 3
// [prefix, prelude]: LCP = 'pre', Length = 3
// [preliminary, presentation]: LCP = 'pre', Length = 3
// [preliminary, prelude]: LCP = 'prel', Length = 4
// [presentation, prelude]: LCP = 'pre', Length = 3
// Hence, among all possible LCP lengths (3, 3, 3, 3, 4, 3), the greatest LCP length is 4.
// Input
// 6 3
// [apple,apply,ant,this,that,there]
// Output
// 2
// Detailed Explanation:
// For k = 3, the best possible LCP length is 2 with "th" as common prefix.
// Input
// 6 2
// [apple,apply,ant,this,that,there]
// Output
// 4
// Detailed Explanation:
// For k = 2, the subset [apple, apply] has the longest common prefix "appl" with length 4.

#include <bits/stdc++.h>
using namespace std;
int getLCP(const string &a,const string &b){
   int lcp=0;
   while(lcp<a.size()&&lcp<b.size() && a[lcp]==b[lcp]){
     lcp++;
   }
   return lcp;
}
int getLCPsubset(vector<string>&s){
   if (s.empty()) return 0;
  string lcs=s[0];
  for(int i=1;i<s.size();i++){  //selected k sized bucket - from the bucked select the max bucket's lcs length
    int len=getLCP(lcs,s[i]);
    if (len == 0) return 0;
    lcs= lcs.substr(0, len);
  }
  return lcs.length();
}
int main() {

  int n,k;
  cin>>n>>k;
  vector<string>s(n);
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  sort(s.begin(),s.end());
  int maxLen=INT_MIN;
  for(int i=0;i<=n-k;i++){
    vector<string> sub(s.begin()+i,s.begin()+i+k);
    maxLen=max(maxLen,getLCPsubset(sub));
  }
  cout<<maxLen;
  return 0;

}
