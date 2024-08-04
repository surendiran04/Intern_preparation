class Solution {
public:
    bool wordPattern(string pattern, string s) { //mapping both string and char to each other
        unordered_map<char, string> patternMap;
        unordered_map<string, char> wordMap;
        istringstream sentence(s);
        string word;
        int i = 0; 
        while (sentence >> word) {
            if (i >= pattern.size()) {
                // More words in the string than pattern characters
                return false;
            }
            char c = pattern[i];
            if (patternMap.count(c)) {
                // Check if the existing mapping is consistent
                if (patternMap[c] != word) {
                    return false;
                }
            } else {
                patternMap[c] = word;
            }

            if (wordMap.count(word)) {
                // Check if the existing mapping is consistent
                if (wordMap[word] != c) {
                    return false;
                }
            } else {
                wordMap[word] = c;
            }

            i++;
        }
        // Ensure both pattern and string are fully processed
        return i == pattern.size();
    }
};
class Solution { //wrong assumed the problem but passed 35/44 cases
// Input
// pattern = "e"
// s = "eukera"
// Output
// false
// Expected
// true
public:
    bool wordPattern(string pattern, string s) {
        char ch='a';
        unordered_map<string,char> map;
        istringstream sentence(s);
        stack<char> s1;
        stack<char> s2;
        string word;
        while(sentence >> word){
            if(map.find(word)==map.end()){
                map[word]=ch;
                s1.push(ch);
                ch++;
            }
            else{
                s1.push(map[word]);
            }
        }
        for(char c:pattern){
            s2.push(c);
        }
        while(!s1.empty() && !s2.empty() && s1.top()==s2.top()){
            s1.pop();
            s2.pop();
        }
        return (s1.empty() && s2.empty())?true:false;
    }
};
