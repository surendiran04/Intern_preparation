//return the min no of swaps req to move all zeros to the front
Input: s = "101"
Output: 1
class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.length();
        if(n==1){
            return 0;
        }
        int l=n-1;
        long long cnt=0;
        for(int r=n-2;r>=0;r--){
            if(s[l]=='0' && s[r]=='1'){
                swap(s[l],s[r]); //transform the original array
                cnt+=l-r;
                l--;
            }else if(s[l]!='0'){
                l--;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    long long minimumSteps(string s) {
        long long swap = 0;
        int black = 0; 
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0')  //for every zeros - we need to add the no of 1's in its left side
                swap += (long long) black; 
            else
                black++; 
        }
        return swap;
    }
};
