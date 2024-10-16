//rearrange the characters of s so that any two adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.
// Input: s = "aab"
// Output: "aba"
// Example 2:
// Input: s = "aaab"
// Output: ""
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> map;
        for(char c:s){
            map[c]++;
        }
        priority_queue<pair<int,char>> maxHeap;
        for(const pair<char,int> &m:map){
            maxHeap.push({m.second,m.first});
        }
        string ans="";
        while(!maxHeap.empty()){
            auto [count1,char1] = maxHeap.top();
            maxHeap.pop();
            if(ans.size()>=1 && ans.back()==char1){
                if(maxHeap.empty()) break;
                auto [count2,char2] = maxHeap.top();
                maxHeap.pop();
                ans+=char2;
                if(--count2 > 0) maxHeap.push({count2,char2});
                maxHeap.push({count1,char1});
            }else{
                ans+=char1;
                if(--count1 > 0) maxHeap.push({count1,char1});
            }
        }
        return ans.length()==s.length()?ans:"";
    }
};
