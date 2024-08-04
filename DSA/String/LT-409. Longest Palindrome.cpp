class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        if(n==1){
            return 1;
        }
        unordered_map<char,int>map;
        for(char c:s){
            map[c]++;
        }
        int len=0;
        bool odd=false;
        for(const pair<char,int> x:map){
            if((x.second & 1)){
                len+=x.second-1;
                odd=true;
            }
            else{
                len+=x.second;
            }
        }
        if(odd){
            len++;
        }
        return len;
    }
};
