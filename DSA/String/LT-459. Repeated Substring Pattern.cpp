class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        for(int i=1;i<=n/2;i++){
            if(n%i==0){  //check that pattern can form the whole string
                string substring=s.substr(0,i);
                string repeated="";
                for(int j=0;j<n/i;j++){ 
                    repeated+=substring;
                }
                if(repeated==s){
                    return true;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    bool repeatedSubstringPattern(string s) { //optimised
        string concatenated = s + s;
        return concatenated.substr(1, concatenated.length() - 2).find(s) != string::npos;
    }
};
