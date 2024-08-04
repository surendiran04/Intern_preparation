// words[i - 1] and words[i] are anagrams, and delete words[i] from words. Keep performing this operation as long as you can select an index that satisfies the conditions.
Input: words = ["abba","baba","bbaa","cd","cd"]
Output: ["abba","cd"]
class Solution { //simple soln
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1; i<words.size(); i++){
            string s1 = words[i];
            string s2 = words[i-1];
            sort(s1.begin(), s1.end());
            sort(s2.begin() ,s2.end());
            if(s1!=s2)
                ans.push_back(words[i]);
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        for(int i=n-1;i>0;i--){
            if(words[i-1].length()==words[i].length() && isAnagram(words[i],words[i-1])){
                words.erase(words.begin()+i); 
            } 
        }
        return words;
    }
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;
        for (auto x : s) {
            count[x]++;
        }
        for (auto x : t) {
            count[x]--;
        }
        for (auto x : count) {
            if (x.second != 0) {
                return false;
            }
        }    
        return true;
    }
};
