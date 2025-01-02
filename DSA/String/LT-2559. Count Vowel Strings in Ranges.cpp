//Count the words within the range which is starting and ending with a vowel
// Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
// Output: [2,3,0]
// Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
// The answer to the query [0,2] is 2 (strings "aba" and "ece").
// to query [1,4] is 3 (strings "ece", "aa", "e").
// to query [1,1] is 0.
// We return [2,3,0].
// Example 2:
// Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
// Output: [3,2,1]
// Explanation: Every string satisfies the conditions, so we return [3,2,1].
    
class Solution { 
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int m=words.size();
        unordered_map<char,int> map;
        map['a']++;
        map['e']++;
        map['i']++;
        map['o']++;
        map['u']++;
        vector<int> prefix(m+1,0);
        for(int i=0;i<m;i++){
            if(map.find(words[i][0])!=map.end() && map.find(words[i][words[i].size()-1])!=map.end()){
                prefix[i+1]=prefix[i]+1;
            }else{
                prefix[i+1]=prefix[i];
            }
        }
        vector<int> res;
        int temp;
        for(auto q:queries){
            if(q[0]==0){
                temp=prefix[q[1]+1];
                res.push_back(temp);
            }else{
                temp=prefix[q[1]+1]-prefix[q[0]];
                res.push_back(temp);
            }
        }
        return res;
    }
};
