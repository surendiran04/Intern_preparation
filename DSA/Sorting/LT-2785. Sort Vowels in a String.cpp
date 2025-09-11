class Solution {
public:
    string sortVowels(string s) {
        int n=s.length();
        unordered_map<char,int> map={{'A',1},{'E',2},{'I',3},{'O',4},{'U',5},{'a',6},{'e',7},{'i',8},{'o',9},{'u',10}};
        vector<char> arr;
        for(char ch:s){
            if(map.find(ch)!=map.end()){  // ASCII value  A-65 , a-97
                arr.push_back(ch);
            }
        }
        sort(begin(arr),arr.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(map.find(s[i])!=map.end()){
                s[i]=arr[j];
                j++;
            }
        }
        return s;
    }
};
class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
            || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }
    
    string sortVowels(string s) {
        unordered_map<char, int> count;    //O(n) - counting sort

        // Store the frequencies for each character.
        for (char c : s) {
            if (isVowel(c)) {
                count[c]++;
            }
        }

        // Sorted string having all the vowels.
        string sortedVowel = "AEIOUaeiou";
        string ans;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!isVowel(s[i])) {
                ans += s[i];
            } else {
                // Skip to the character which is having remaining count.
                while (count[sortedVowel[j]] == 0) {
                    j++;
                }

                ans += sortedVowel[j];
                count[sortedVowel[j]]--;
            }
        }
        return ans;
    }
};
