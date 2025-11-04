class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) { //exponential time - O(W × 2^N × N)
        vector<string> res;
        for(auto word:wordDict){
            if(s.substr(0,word.length())==word){
                if(word.length()==s.length()){
                    res.push_back(word);
                }else{
                    vector<string> temp=wordBreak(s.substr(word.length()),wordDict);
                    for(string t:temp){
                        res.push_back(word+" "+t);
                    }
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    unordered_map<string, vector<string>> memo; //memoization  - TC:O(N² × W)

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (memo.count(s)) return memo[s];

        vector<string> res;

        for (auto& word : wordDict) {
            if (s.rfind(word, 0) == 0) { // checks if s starts with word
                if (word.length() == s.length()) {
                    res.push_back(word);
                } else {
                    vector<string> temp = wordBreak(s.substr(word.length()), wordDict);
                    for (string& t : temp) {
                        res.push_back(word + " " + t);
                    }
                }
            }
        }

        return memo[s] = res;
    }
};
