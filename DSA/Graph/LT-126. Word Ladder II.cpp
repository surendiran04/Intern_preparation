class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) { //Got MLE in leetcode since N=500 in GFG N=100 so passed all the TC's
        queue<vector<string>> q;
        unordered_set<string> words(wordList.begin(),wordList.end());
        q.push({beginWord});
        int level=1;
        vector<string> usedLevel;
        usedLevel.push_back(beginWord);
        vector<vector<string>> ans;
        while(!q.empty()){
            vector<string> vec=q.front();q.pop();
            if(vec.size()>level){
                level++;
                for(string s:usedLevel){
                    words.erase(s);
                }
                usedLevel.clear();
            }
            string word=vec.back();
            if(word==endWord){
                if(ans.size()==0){
                    ans.push_back(vec);
                }else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i=0;i<word.size();i++){
                char orgChar=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(words.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                        usedLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]=orgChar;
            }
        }
        return ans;
    }
//Backtrack from the endword to the prev levels and find the answer using the approach from word ladder1
class Solution {
public:
    string b;
    vector<vector<string>> ans;
    unordered_map<string,int> map;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
         queue<pair<string,int>> q;
        q.push({beginWord,1});
        b=beginWord;
        map[beginWord]=1;
        unordered_set<string> words(wordList.begin(),wordList.end());
        words.erase(beginWord);
        while(!q.empty()){
            auto [word,steps]=q.front();
            q.pop();
            if(word==endWord){
                break;
            }
            for(int i=0;i<word.size();i++){
                char orgChar=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(words.find(word)!=words.end()){
                        words.erase(word);
                        q.push({word,steps+1});
                        map[word]=steps+1;
                    }
                }
                word[i]=orgChar;
            }
        }
        if(map.find(endWord)!=map.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
    void dfs(string word,vector<string>& seq){
        if(word==b){
            reverse(begin(seq),end(seq));
            ans.push_back(seq);
            reverse(begin(seq),end(seq));
            return;
        }
        int steps=map[word];
        for(int i=0;i<word.size();i++){
            char orgChar=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(map.find(word)!=map.end() && map[word]+1==steps){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i]=orgChar;
        }

    }
};
};
