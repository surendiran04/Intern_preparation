int d=256; //Base or Radix also can be m+n
int q=101;  //prime no
void rabin_karp(string s,string p){
    int n=s.length(),m=p.length();
    int h=1;
    for(int i=0;i<m-1;i++){
        h=(h*d)%q;
    }
    int hash_t=0,hash_p=0;
    for(int i=0;i<m;i++){
        hash_t=(hash_t*d+s[i])%q;
        hash_p=(hash_p*d+p[i])%q;
    }
    for(int i=0;i<=n-m;i++){
        if(hash_t==hash_p){
            if(s.substr(i,m)==p){
                cout<<"Pattern found at "<<i<<endl;
            }
        }
        if(i<n-m){
            hash_t=(d*(hash_t-s[i]*h)+s[i+m])%q;  //remmving pre value and adding new value
            if(hash_t<0){
                hash_t+=q;
            }
        }
    }
}
int main() {
	rabin_karp("abcdxabcdfabcdf","abcdf");
