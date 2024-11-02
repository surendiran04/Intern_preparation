// Input: sentence = "leetcode exercises sound delightful"
// Output: true
// Explanation: The words in sentence are ["leetcode", "exercises", "sound", "delightful"].
// - leetcode's last character is equal to exercises's first character.
// - exercises's last character is equal to sound's first character.
// - sound's last character is equal to delightful's first character.
// - delightful's last character is equal to leetcode's first character.
// The sentence is circular.
class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence[0]!=sentence.back()){
            return false;
        }
        istringstream ss(sentence);
        string n;
        vector<string> s;
        while(ss>>n){
            s.push_back(n);
        }
        for(int i=0;i<s.size()-1;i++){
            if(s[i].back()!=s[i+1][0]){
                return false;
            }
        }
        return true;
    }
};

class Solution {  //space optimised approach
public:
    bool isCircularSentence(string sentence) {
        for (int i = 0; i < sentence.size(); ++i)
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
                return false;
        return sentence[0] == sentence[sentence.size() - 1];
    }
};
