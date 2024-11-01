//A fancy string is a string where no three consecutive characters are equal.
// Input: s = "leeetcode"
// Output: "leetcode"
class Solution {
public:
    string makeFancyString(string s) {
        int cnt = 1, n = s.length();
        char x = s[0];
        string res="";
        res.push_back(x);
        for (int i = 1; i < n; i++) {  //TLE error
            if (x == s[i]) {
                cnt++;
            } else {
                x = s[i];
                cnt = 1;
            }
            if (cnt < 3){
                res = res + x;
            }
        }
        return res;
    }
};

class Solution { //In-Place deletion 
public:
    string makeFancyString(string s) {
        int n=s.length();
        if(n<3){
            return s;
        }
       int cnt=1,j=2;
       for(int i=2;i<n;i++){
        if(s[i]!=s[j-1] || s[i]!=s[j-2]){
            s[j++]=s[i];
        }
       }
       s.resize(j);
       return s;
    }
};

class Solution { //istring stream approach
public:
    string makeFancyString(string s) {
        stringstream ss;
        ss << s[0];

        int count = 1;
        for(int i=1; i<s.size(); i++){
            if(s[i] == s[i-1]) count++;
            else count = 1;

            if(count >= 3) continue;
            ss << s[i];
        }

        return ss.str();
    }
};
