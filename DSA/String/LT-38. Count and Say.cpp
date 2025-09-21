class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        for(int i=1;i<n;i++){
            res=gen(res);
            cout<<res<<" ";
        }
        return res;
    }
    string gen(string s){
        int n=s.length();
        string res="";
        for(int i=0;i<n;){
            int cnt=0;char ch=s[i];
            while(i+cnt<n && ch==s[i+cnt]){
                cnt++;
            }
            res=res+to_string(cnt);
            res+=ch;
            i+=cnt;
        }
        return res;
    }
};
