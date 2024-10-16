// A string s is called happy if it satisfies the following conditions:
// s only contains the letters 'a', 'b', and 'c'.
// s does not contain any of "aaa", "bbb", or "ccc" as a substring.
// s contains at most a occurrences of the letter 'a'.
// s contains at most b occurrences of the letter 'b'.
// s contains at most c occurrences of the letter 'c'.
// Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
// A substring is a contiguous sequence of characters within a string.

// Example 1:
// Input: a = 1, b = 1, c = 7
// Output: "ccaccbcc"
// Explanation: "ccbccacc" would also be a correct answer.
  
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {  //Best approach 0(1) space complexity
        string ans="";
        int len=a+b+c,i=0;
        int streakA=0,streakB=0,streakC=0;
        while(i<len){
            if( (a>=b && a>=c && streakA<2) || (a>0 && (streakB>1 || streakC>1)) ){
                ans+='a';
                streakB=0;
                streakC=0;
                streakA++;
                a--;
            }
            else if( (b>=a && b>=c && streakB<2) || (b>0 && (streakA>1 || streakC>1)) ){
                ans+='b';
                streakA=0;
                streakC=0;
                streakB++;
                b--;
            }
            else if( (c>=a && c>=b && streakC<2) || (c>0 && (streakA>1 || streakB>1)) ){
                ans+='c';
                streakA=0;
                streakB=0;
                streakC++;
                c--;
            }
            i++;
        }
        return ans;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) { //Heap approach 
        string res;
        priority_queue<pair<int, char>> maxHeap;

        if (a > 0) maxHeap.push({a, 'a'});
        if (b > 0) maxHeap.push({b, 'b'});
        if (c > 0) maxHeap.push({c, 'c'});

        while (!maxHeap.empty()) {
            auto [count1, char1] = maxHeap.top(); //always taking the max element
            maxHeap.pop();

            if (res.size() > 1 && res.back() == char1 && res[res.size() - 2] == char1) { //suppose there 2 times the max element occurs, 2nd max comes into picture
                if (maxHeap.empty()) break;

                auto [count2, char2] = maxHeap.top();
                maxHeap.pop(); 
                res += char2;
                if (--count2 > 0) maxHeap.push({count2, char2});

                maxHeap.push({count1, char1});
            } else {
                res += char1;
                if (--count1 > 0) maxHeap.push({count1, char1});
            }
        }
        return res;
    }
};
