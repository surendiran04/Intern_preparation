class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) { //TC:O(N*M*26*logN) ,M- word len
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> words(wordList.begin(),wordList.end());
        words.erase(beginWord);
        while(!q.empty()){
            auto [word,steps]=q.front();
            q.pop();
            if(word==endWord){
                return steps;
            }
            for(int i=0;i<word.size();i++){
                char orgChar=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(words.find(word)!=words.end()){ //check if it exist in the words
                        words.erase(word);
                        q.push({word,steps+1}); //Same level so same steps
                    }
                }
                word[i]=orgChar;
            }
        }
        return 0;
    }
};
