#include <bits/stdc++.h>
using namespace std;
vector<int> computeLPS(string pat);
void kmp(string s,string pat){
    int n=s.length(),m=pat.length();
    vector<int> lps=computeLPS(pat);
    for(int i=0,j=0;i<n;){
        if(s[i]==pat[j]){
            i++;j++;
        }
        if(j==m){
            cout<<"Pattern found at "<<(i-j)<<endl;
            j=lps[j-1];
        }else if(i<n && s[i]!=pat[j]){
            if(j!=0){
                j=lps[j-1];
            }else{
                i++;
            }
        }
    }
}
vector<int> computeLPS(string pat){
    int m=pat.length();
    vector<int> lps(m,0);
    for(int i=1,len=0;i<m;){
        if(pat[i]==pat[len]){
            lps[i++]=++len;
        }else{
            if(len){
                len=lps[len-1];
            }else{
                i++;
            }
        }
    }
    return lps;
}
int main() {
	kmp("abcdxabcdfabcdf","abcdf");

}
