//Input: s = "ababccc"
// Output: 5
// Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. 
class Solution {
public:
    int maxUniqueSplit(string s) {
        set<string> set;
        int maxSize=0;
        backtrack(s,0,set,maxSize);
        return maxSize;
    }
    void backtrack(string &s,int start,set<string> &set,int &maxSize){
        string c="";
        for(int i=start;i<s.length();i++){
            c += s[i];
            if(set.find(c)==set.end()){
                set.insert(c);
                maxSize=max(maxSize,(int)set.size());
                backtrack(s,i+1,set,maxSize);
                set.erase(c);
            }
        }
    }
};
