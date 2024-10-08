// Input: s = "][]["
// Output: 1
// Explanation: You can make the string balanced by swapping index 0 with index 3.
// The resulting string is "[[]]".
// Input: s = "]]][[["
// Output: 2  "[[][]]"
class Solution {
public:
    int minSwaps(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                if(count==0){
                    count++;
                }else{
                    count--;
                }
            }else{
                count++;
            }
        }
        return (count+1)/2;
    }
};

class Solution {
public:
    int minSwaps(string s) {
        stack<char> st; // Stack to track unbalanced parentheses

        for(auto &i : s)
            if(i == '[')
                st.push(i); 
            else if(!st.empty() && st.top() == '[')
                st.pop(); // Excluding balanced pairs
            else
                st.push(i); // Push closing bracket

        int unbalancedPairs = st.size() / 2;
        int swaps = ceil(unbalancedPairs / 2.0); //ceil will take care of +1
        return swaps;
    }
};
