class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) { 
        int n=s.length();
        string res;
        int cnt=0,l=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
            }
            while(cnt>k){
                if(s[l]=='1'){
                    cnt--;
                }
                l++;
            }
            if(cnt==k){
                string t=s.substr(l,i-l+1);
                int j=0;
                while(j<i-l && t[j]=='0'){
                    j++;
                }
                t=t.substr(j,i-j+1);
                if(res.empty() || t.size()<res.size() || t.size()==res.size() && t<res){
                    res=t;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) { // Optimised in terms of space
        int n=s.length();
        string res;
        int cnt=0,l=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
            }
            while(cnt>k || s[l]=='0'){
                if(s[l]=='1'){
                    cnt--;
                }
                l++;
            }
            if(cnt==k){
                string t=s.substr(l,i-l+1);
                if(res.empty() || t.size()<res.size() || t.size()==res.size() && t<res){
                    res=t;
                }
            }
        }
        return res;
    }
};
