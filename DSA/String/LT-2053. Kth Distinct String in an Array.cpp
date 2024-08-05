// Input: arr = ["d","b","c","b","c","a"], k = 2
// Output: "a"
// Explanation:
// The only distinct strings in arr are "d" and "a".
// "d" appears 1st, so it is the 1st distinct string.
// "a" appears 2nd, so it is the 2nd distinct string.
// Since k == 2, "a" is returned. 
// Example 2:
// Input: arr = ["aaa","aa","a"], k = 1
// Output: "aaa"
// Explanation:
// All strings in arr are distinct, so the 1st string "aaa" is returned.
// Example 3:
// Input: arr = ["a","b","a"], k = 3
// Output: ""
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> map;
        for(string c:arr){
            map[c]++;
        }
        for(string x:arr){
            if(map[x]==1){
                k--;
            }
            if(k==0){
                return x;
            }
        }
        return "";
    }
};
