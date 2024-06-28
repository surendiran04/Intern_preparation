Input: s = "iloveleetcode", words = ["i","love","leetcode","apples"]
Output: true
Input: s = "iloveleetcode", words = ["apples","i","love","leetcode"]
Output: false
A string s is a prefix string of words if s can be made by concatenating the first k strings in words for some positive k no larger than words.length.
  
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string x;
        for(int i=0;i<words.size();i++){
            x+=words[i];
            if(x==s){                          
                return true;
            }
        }
        return false;
    }
};

class Solution {  //better approach to stop iteration with edge cases
public:
    bool isPrefixString(string s, vector<string>& words) {
        string x;
        for(int i=0;i<words.size();i++){
            x+=words[i];
            if(x.length()==s.length()){
                return x==s;
            }
          if(x.length()>s.length()){
                return false;
            }
        }
        return false;
    }
};
