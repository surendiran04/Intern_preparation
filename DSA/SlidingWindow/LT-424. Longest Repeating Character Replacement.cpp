// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. 
// You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// Example 1:
// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:
// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.
  
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen=0,l=0,maxcount=0;
        int n=s.length();
        unordered_map<char,int> map;
        for(int r=0;r<n;r++){
            map[s[r]]++;
            maxcount=max(maxcount,map[s[r]]);
            if(r-l+1-maxcount>k){ //remaining elements other than max element
               map[s[l]]--;
               l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};
class Solution { //passed only 33/45 cases
public:
    int characterReplacement(string s, int k) {
        int maxlen=0;
        int n=s.length();
        unordered_map<char,int> map;
        for(char c:s){
            map[c]++;
        }
        char x;
        int max=0;
        for(const pair<char,int> p:map){
            if(p.second>max){
                max=p.second;
                x=p.first;
            }
        }
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=i;j<n;j++){
                if(s[j]!=x){
                    count++;
                }
                if(count<=k && j-i+1>maxlen){
                    maxlen=j-i+1;
                }
                if(count>k) break;
            }
        }
        return maxlen;
    }
};
