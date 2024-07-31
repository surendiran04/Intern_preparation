// Input: s = "the sky is blue"
// Output: "blue is sky the"
class Solution {
public:
    string reverseWords(string s) {
       vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        string result;
        int n=words.size();
        for (int i = n-1; i>=0;i--) {
            if (i < n-1) {
                result += " ";
            }
            result += words[i];
        }
        return result;
    }
};

class Solution { //inplace swap
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end()); 
        int start=0,end=0,i=0;
        int n=s.length();
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            if(i==n) break; //for stopping from unecessary spacing
            while(i<n &&s[i]!=' '){
                s[start++]=s[i++];
            }
            reverse(s.begin()+end,s.begin()+start); //reverse the word
            s[start++]=' '; //manually adding space
            end=start;      //end will take care of the new word's starting
            i++;
        }
        s.resize(start-1);
        return s;
    }
};
