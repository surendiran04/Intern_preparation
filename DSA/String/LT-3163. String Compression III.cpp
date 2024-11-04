// Input: word = "abcde"
// Output: "1a1b1c1d1e"
// Input: word = "aaaaaaaaaaaaaabb"
// Output: "9a5a2b"
class Solution {
public:
    string compressedString(string word) {  //while using string and '+' got MLE so better to use vector<char> or +=
        vector<char> res;
        int cnt = 1, n = word.length();
        char s = word[0];
        for (int i = 1; i < n; i++) {
            if (s == word[i]) {
                cnt++;
            } else {
                while (cnt > 0) {  //also we can stop using this while by using a cnt>8 condition in the above if 
                    if (cnt > 8) {
                        res.push_back(9+'0');
                        res.push_back(s);
                        cnt = cnt - 9;
                    } else {
                        res.push_back(cnt+'0');
                        res.push_back(s);
                        cnt = 0;
                    }
                }
                cnt = 1;
                s = word[i];
            }
        }
        while (cnt > 0) {
            if (cnt > 8) {
                res.push_back(9+'0');
                res.push_back(s);
                cnt = cnt - 9;
            } else {
                res.push_back(cnt+'0');
                res.push_back(s);
                cnt = 0;
            }
        }
        string str(res.begin(),res.end());
        return str;
    }
};
 // += is faster than = + so the same code after changing to += got passed
class Solution {
public:
    string compressedString(string word) {
        string res = "";
        int cnt = 1, n = word.length();
        char s = word[0];
        for (int i = 1; i < n; i++) {
            if (s == word[i]) {
                cnt++;
            } else {
                while (cnt > 0) {
                    if (cnt > 8) {
                        res += to_string(9) + s;
                        cnt = cnt - 9;
                    } else {
                        res += to_string(cnt) + s;
                        cnt = 0;
                    }
                }
                cnt = 1;
                s = word[i];
            }
        }
        while (cnt > 0) {
            if (cnt > 8) {
                res += to_string(9) + s;
                cnt = cnt - 9;
            } else {
                res += to_string(cnt) + s;
                cnt = 0;
            }
        }
        return res;
    }
};
