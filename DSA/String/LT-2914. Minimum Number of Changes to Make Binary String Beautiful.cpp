//A string is beautiful if it's possible to partition it into one or more substrings such that:
// Each substring has an even length.
// Each substring contains only 1's or only 0's.
// You can change any character in s to 0 or 1.
// Return the minimum number of changes required to make the string s beautiful.

// s = "01010001"
// output:3
class Solution {
public:
    int minChanges(string s) {
        int n=s.length();
        int res=0;
        for(int i=1;i<n;i+=2){
            if(s[i-1]!=s[i]){  //actually it is sliding if size 2
                res++;
            }
        }
        return res;
    }
};
