Input: words = ["a","b","c","ab","bc","abc"], s = "abc"
Output: 3
Input: words = ["a","a"], s = "aa"
Output: 2
//return the count of strings in words that either contain the prefix of s if 'a' == 'abc' but if the string contain more char then check other characters as well
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count=0;
        for(string word:words){
            if(word==s.substr(0,word.length())){   //another logic  if(s.find(word)==0){
                count++;
            }
        }
        return count;
    }
};
