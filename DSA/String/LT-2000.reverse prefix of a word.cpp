Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Input: word = "abcd", ch = "z"
Output: "abcd"

//reversing the prefix until 'ch' in the given string
    
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index=word.find(ch);
        string subString = word.substr(0,index+1);
        reverse(subString.begin(),subString.end()); //reversing the string until ch and doing concatenation
        return subString+word.substr(index+1);
    }
};
