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
                swap(s[l],s[r]);
                cnt+=l-r;
                l--;
            }else if(s[l]!='0'){
                l--;
            }
        }
        return cnt;
    }
};
