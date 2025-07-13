// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.
// Example 2:

// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.
// Example 3:

// Input: s = "luffy is still joyboy"
// Output: 6

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        string t="";
        for(int i=0;i<n;i++){
            if(i+1<n && s[i]==' ' && s[i+1]!=' '){
                t="";
            }else if(s[i]!=' '){
                t+=s[i];
            }
        }
        return t.length();
    }
};

int lengthOfLastWord(string s) { // from reverse
    int i = s.length() - 1;
    
    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') i--;
    
    int length = 0;
    // Count length of last word
    while (i >= 0 && s[i] != ' ') { //loop will cut-off once finding a space after a word
        length++;
        i--;
    }
    
    return length;
}
