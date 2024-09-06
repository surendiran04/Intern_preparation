// Input: coordinate1 = "a1", coordinate2 = "c3"
// Output: true
// Explanation:
// Both squares are black.
// Example 2:
// Input: coordinate1 = "a1", coordinate2 = "h3"
// Output: false
// Explanation:
// Square "a1" is black and "h3" is white.
  
class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int n1=(coordinate1[0]-'a'+1);
        int n2=(coordinate2[0]-'a'+1);
        int i=coordinate1[1]-'0';
        int j=coordinate2[1]-'0';
        return (n1%2==i%2 && n2%2==j%2) || (!(n1%2==i%2) && !(n2%2==j%2)); //if both n1 and i are equal then it pointing to black or white checking same for 2nd input
    }
};
