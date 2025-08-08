// Example 1:
// Input: n = 12
// Output: 21
// Example 2:
// Input: n = 21
// Output: -1

class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        long long ans=0;
        if(next_permutation(s.begin(),s.end())){
            for(char ch:s){
                ans=ans*10+(ch-'0'); //for longer inputs
                if(ans>INT_MAX){
                    return -1;
                }
            }
            return ans;
        }else{
            return -1;
        }
    }
};
