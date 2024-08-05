// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:
// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:
// Input: s = "a", t = "aa"
// Output: ""
class Solution {
public:
    string minWindow(string s, string t) { //passes 265 out of 268 and got TLE error
        int m=s.length();
        int n=t.length();
        if(m<n){
            return "";
        }
        int minlen=INT_MAX,cnt=0,start=-1;
        for(int i=0;i<m;i++){
            unordered_map<char,int> map;
            cnt=0;
            for(char c:t){
              map[c]++;
            }
            for(int j=i;j<m;j++){
                if(map[s[j]]>0){
                    cnt++;
                }
                map[s[j]]--;
                if(cnt==n){
                    if(j-i+1<minlen){
                        minlen=j-i+1;
                        start=i;
                        break;
                    }
                }
            }
        }
        return (start==-1)?"":s.substr(start,minlen);
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (m < n) {
            return "";
        }
        unordered_map<char, int> map;
        for (char c : t) {
            map[c]++;
        }
        int minlen = INT_MAX, cnt = 0, start = -1, l = 0;
        for (int r = 0; r < m; r++){
                if (map[s[r]] > 0) {
                    cnt++;
                }
                map[s[r]]--;
                while (cnt == n){
                    if (r - l + 1 < minlen) {
                        minlen = r - l + 1;
                        start = l;
                    }
                    map[s[l]]++;
                    if (map[s[l]] > 0) {
                        cnt--;
                    }
                    l++;
                }
            }
        return (start == -1) ? "" : s.substr(start, minlen);
    }
};
