class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> set;
        int count=0;
        for(char ch:s){
            if(!set.count(ch)){ //maximize the no of substrings split - abca -> a,b,c | abcd -> a,b,c,d | aaaa -> a 
                count++;
                set.insert(ch);
            }
        }
        return count;
    }
};
