class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m=b.length();
        int cnt=1;
        string txt=a;
        while((int)txt.length()<m){
            txt+=a;
            cnt++;
        }
        if(RabinKarp(txt,b)){
            return cnt;
        }
        txt+=a;
        cnt++;
        if(RabinKarp(txt,b)){
            return cnt;
        }
        return -1;
    }
    int d=256; //m+n
    int q=101; //prime no else keep 1e9+7 which is the largets prime number
    bool RabinKarp(string& txt,string& pat){
        int n=txt.length(),m=pat.length();
        int h=1;
        for(int i=0;i<m-1;i++){
            h=(h*d)%q;
        }
        int hash_p=0,hash_t=0;
        for(int i=0;i<m;i++){
            hash_p=(hash_p*d+pat[i])%q;
            hash_t=(hash_t*d+txt[i])%q;
        }
        for(int i=0;i<=n-m;i++){
            if(hash_p==hash_t){
                if(txt.substr(i,m)==pat){
                    return true;
                }
            }
            if(i<n-m){
                hash_t=(d*(hash_t-txt[i]*h)+txt[i+m])%q;
                if(hash_t<0){
                    hash_t+=q;
                }
            }
        }
       return false;
    }
};
