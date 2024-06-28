Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Input: sentence = "i am tired", searchWord = "you"
Output: -1
  
class Solution {     //beats 100%
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index=0;
        int n = searchWord.length();
        istringstream ss(sentence);   //splits the sentence into words
        string word;
        while (ss >> word) {
            index++;
           if(word.substr(0,n) == searchWord){
            return index;
            }
           
        }
        return -1;     
    }
};
