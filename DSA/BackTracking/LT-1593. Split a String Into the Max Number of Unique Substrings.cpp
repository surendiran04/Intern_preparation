//Input: s = "ababccc"
// Output: 5
// Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. 
class Solution {
public:
    int maxUniqueSplit(string s) { //T(n) - exponential
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
class Solution { //T(n) - O(2^n)
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        return backtrack(s,0,set);
    }
    int backtrack(string& s,int start,unordered_set<string> &set){
        int max_size=set.size();
        for(int end=start;end<s.size();end++){
            string c = s.substr(start,end-start+1);
            if(set.find(c)==set.end()){
                set.insert(c);
                max_size=max(max_size,backtrack(s,end+1,set));
                set.erase(c);
            }
        }
        return max_size;
    }
};
