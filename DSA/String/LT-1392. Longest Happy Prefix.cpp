class Solution {
public:
    string longestPrefix(string s) { //memeory limit execedded
        int n=s.length();
        string t=s;
        reverse(begin(t),end(t));
        vector<string> prefix,suffix;
        for(int i=0;i<n-1;i++){
            prefix.push_back(s.substr(0,n-i-1));
            string temp=t.substr(0,n-i-1);
            reverse(begin(temp),end(temp));
            suffix.push_back(temp);
        }
        string ans;
        for(int i=0;i<n-1;i++){
            if(prefix[i]==suffix[i]){
                ans=prefix[i];
                break;
            }
        }
        return ans;
    }
};

class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        vector<int> lps=computeLPS(s);
        return s.substr(0,lps.back());
    }
    vector<int> computeLPS(string& s){
        int n=s.length();
        vector<int> lps(n,0);
        for(int i=1,len=0;i<n;){
            if(s[i]==s[len]){
                lps[i++]=++len;
            }else{
                if(len>0){
                    len=lps[len-1];
                }else{
                    i++;
                }
            }
        }
        return lps;
    }
};
