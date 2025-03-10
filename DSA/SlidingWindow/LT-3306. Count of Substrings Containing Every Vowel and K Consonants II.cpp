// Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.
// Input: word = "aeioqq", k = 1
// Output: 0
// Input: word = "aeiou", k = 0
// Output: 1
// word ="iqeaouqi", k = 2
// Output:3
class Solution {
public:
    long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }

private:
    long atLeastK(string word, int k) {
        long numValidSubstrings = 0;
        int start = 0;
        int end = 0;
        unordered_map<char, int> vowelCount;
        int consonantCount = 0;

        while (end < word.length()) {
            char newLetter = word[end];

            if (isVowel(newLetter)) {
                vowelCount[newLetter]++;
            } else {
                consonantCount++;
            }

            while (vowelCount.size() == 5 and consonantCount >= k) {
                numValidSubstrings += word.length() - end;
                char startLetter = word[start];
                if (isVowel(startLetter)) {
                    if (--vowelCount[startLetter] == 0) {
                        vowelCount.erase(startLetter);
                    }
                } else {
                    consonantCount--;
                }
                start++;
            }

            end++;
        }

        return numValidSubstrings;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
class Solution { //didn't pass all cases
public:
    unordered_map<char,int>map={{'a',1},{'e',1},{'o',1},{'u',1},{'i',1}}; 
    long long countOfSubstrings(string word, int k) {
        long res=0;
        for(int i=0;i<word.length();i++){
            if(check(word.substr(i,5+k),k)){
                res++;
            }
        }
        return res;
    }
    bool check(string word,int k){
        int vcount=0,count=0;
        for(char w:word){
            if(map.find(w)!=map.end()){
                vcount++;
            }else{
                count++;
            }
        }
        return (vcount==5 && count==k);
    }
};
