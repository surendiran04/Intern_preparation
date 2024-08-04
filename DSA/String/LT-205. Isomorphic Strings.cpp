// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> v1(200, 0);
        vector<int> v2(200, 0);
        for (int i = 0; i < s.size(); i++) {
            if(v1[s[i]]!=v2[t[i]]){
                return false;

            }
            v1[s[i]]=i+1;
            v2[t[i]]=i+1;
        }
        return true;
    }
};
